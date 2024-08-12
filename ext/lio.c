#include "lio.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void lio_wsetup(struct lio_writer *x, int fd)
{
  x->fd = fd;
  memset(x->buffer, 0, LIO_BUFFER_SIZE);
  x->backlog = 0;
  x->allocated = 0;
}

static inline int full_write(int fd, size_t size, unsigned char const *buffer)
{
  while (size > 0)
  {
    ssize_t n = write(fd, buffer, size);
    if (n == -1) return -1;
    buffer += n;
    size -= (size_t)n;
  }
  return 0;
}

int lio_write(struct lio_writer *x, size_t size)
{
  if (size == 0) return 1;
  if (size > x->allocated) return 1;
  x->backlog += size;
  x->allocated = 0;
  if (LIO_BUFFER_SIZE - x->backlog < LIO_HEADER_SIZE) return lio_flush(x);
  return 0;
}

unsigned char *lio_alloc(struct lio_writer *x)
{
  x->allocated = LIO_BUFFER_SIZE;
  return x->buffer + x->backlog;
}

int lio_writeb(struct lio_writer *x, size_t size, void const *data)
{
  if (x->allocated > 0) return 1;
  if (x->backlog + size + LIO_HEADER_SIZE > LIO_BUFFER_SIZE && lio_flush(x)) return 1;
  if (size + LIO_HEADER_SIZE > LIO_BUFFER_SIZE) return full_write(x->fd, size, data);
  memcpy(x->buffer + x->backlog, data, size);
  x->backlog += size;
  return 0;
}

int lio_flush(struct lio_writer *x)
{
  if (x->allocated > 0) return 1;
  if (full_write(x->fd, x->backlog, x->buffer)) return 1;
  x->backlog = 0;
  return 0;
}

int lio_wfile(struct lio_writer const *x) { return x->fd; }

int lio_wtell(struct lio_writer const *x, long *offset)
{
  if ((*offset = lseek(x->fd, 0, SEEK_CUR)) < 0) return 1;
  *offset += (off_t)x->backlog;
  return 0;
}

int lio_wseek(struct lio_writer *x, long offset)
{
  if (x->allocated > 0) return 1;
  if (lio_flush(x)) return 1;
  if (lseek(x->fd, (off_t)offset, SEEK_SET) < 0) return 1;
  return 0;
}

int lio_wrewind(struct lio_writer *x) { return lio_wseek(x, 0); }

void lio_rsetup(struct lio_reader *x, int fd)
{
  x->fd = fd;
  memset(x->buffer, 0, LIO_BUFFER_SIZE);
  x->invalid_buffer[0] = 0xc1;
  x->head = 0;
  x->tail = 0;
}

static inline void align(struct lio_reader *x)
{
  size_t size = x->tail - x->head;
  memmove(x->buffer, x->buffer + x->head, size);
  x->head = 0;
  x->tail = size;
}

unsigned char *lio_read(struct lio_reader *x)
{
  size_t active = x->tail - x->head;
  if (active >= LIO_HEADER_SIZE) return x->buffer + x->head;

  if (active == 0) align(x);
  if (LIO_BUFFER_SIZE - x->head < LIO_HEADER_SIZE) align(x);

  if (LIO_BUFFER_SIZE > x->tail && !x->_feof)
  {
    ssize_t n = read(x->fd, x->buffer + x->tail, LIO_BUFFER_SIZE - x->tail);
    if (n == 0) x->_feof = 1;
    if (n == -1) return x->invalid_buffer;
    x->tail += (size_t)n;
  }

  if (x->tail - x->head == 0) return x->invalid_buffer;

  return x->buffer + x->head;
}

static inline int full_read(int fd, size_t size, unsigned char *buffer)
{
  while (size > 0)
  {
    ssize_t n = read(fd, buffer, size);
    if (n == -1 || n == 0) return -1;
    buffer += n;
    size -= (size_t)n;
  }
  return 0;
}

int lio_readb(struct lio_reader *x, size_t size, unsigned char *data)
{
  size_t n = size <= x->tail - x->head ? size : x->tail - x->head;
  memcpy(data, x->buffer + x->head, n);
  x->head += n;

  return n < size ? full_read(x->fd, size - n, data + n) : 0;
}

int lio_free(struct lio_reader *x, size_t size)
{
  if (size == 0) return 1;
  if (x->head + size > x->tail) return 1;
  x->head += size;
  return 0;
}

int lio_eof(struct lio_reader const *x) { return x->_feof && (x->tail - x->head) == 0; }

int lio_rfile(struct lio_reader const *x) { return x->fd; }

int lio_rtell(struct lio_reader const *x, long *offset)
{
  if ((*offset = lseek(x->fd, 0, SEEK_CUR)) < 0) return 1;
  size_t active = x->tail - x->head;
  *offset -= (off_t)active;
  return 0;
}

int lio_rseek(struct lio_reader *x, long offset)
{
  if (lseek(x->fd, (off_t)offset, SEEK_SET) < 0) return 1;
  x->head = 0;
  x->tail = 0;
  return 0;
}

int lio_rrewind(struct lio_reader *x) { return lio_rseek(x, 0); }
