#ifndef LITE_PACK_IO_H
#define LITE_PACK_IO_H

#include "lite_pack.h"

#define LIO_BUFFER_SIZE 0x40000
#define LIO_HEADER_SIZE 9

struct lio_writer
{
  int fd;
  unsigned char buffer[LIO_BUFFER_SIZE];
  size_t backlog;
  size_t allocated;
};

struct lio_reader
{
  int fd;
  unsigned char buffer[LIO_BUFFER_SIZE];
  unsigned char invalid_buffer[1];
  size_t head;
  size_t tail;
};

void           lio_writer_init(struct lio_writer *, int fd);
unsigned char *lio_alloc(struct lio_writer *);
int            lio_write(struct lio_writer *, size_t size);
int            lio_writeb(struct lio_writer *, size_t size, void const *data);
int            lio_flush(struct lio_writer *);

void           lio_reader_init(struct lio_reader *, int fd);
unsigned char *lio_read(struct lio_reader *);
int            lio_readb(struct lio_reader *, size_t size, unsigned char *data);
int            lio_free(struct lio_reader *, size_t size);

#endif
