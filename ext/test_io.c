#include "lite_pack_io.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

static char const hello[] = "Hello, world!";

static int test_writer(void)
{

  int fd = open("io.mp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (!fd) return 1;

  struct lio_writer io = {0};
  lio_writer_init(&io, fd);

  for (int i = 0; i < 120000; i++)
  {
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), 0))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), +1))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), +10))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), +100))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), +1000))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), +10000))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), +100000))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), +1000000))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), +10000000))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), +100000000UL))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), +1000000000UL))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), -1))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), -10))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), -100))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), -1000))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), -10000))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), -100000))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), -1000000))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), -10000000))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), -100000000L))) return 1;
    if (lio_write(&io, lip_pack_int(lio_alloc(&io), -1000000000L))) return 1;

    if (lio_write(&io, lip_pack_string(lio_alloc(&io), strlen(hello)))) return 1;
    if (lio_writeb(&io, strlen(hello), hello)) return 1;
  }

  if (lio_flush(&io)) return 1;
  return close(fd) ? 1 : 0;
}

static int test_reader(void)
{
  uint32_t u32 = 0;
  uint64_t u64 = 0;
  int64_t i64 = 0;
  unsigned char buffer[sizeof(hello) - 1] = {0};

  int fd = open("io.mp", O_RDONLY, 0644);
  if (!fd) return 1;

  struct lio_reader io = {0};
  lio_reader_init(&io, fd);

  for (int i = 0; i < 120000; i++)
  {
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 0) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 1) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 10) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 100) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 1000) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 10000) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 100000) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 1000000) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 10000000) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 100000000UL) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &u64)) || u64 != 1000000000UL) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &i64)) || i64 != -1) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &i64)) || i64 != -10) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &i64)) || i64 != -100) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &i64)) || i64 != -1000) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &i64)) || i64 != -10000) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &i64)) || i64 != -100000) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &i64)) || i64 != -1000000) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &i64)) || i64 != -10000000) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &i64)) || i64 != -100000000L) return 1;
    if (lio_free(&io, lip_unpack_int(lio_read(&io), &i64)) || i64 != -1000000000L) return 1;

    if (lio_free(&io, lip_unpack_string(lio_read(&io), &u32)) || u32 != sizeof(buffer)) return 1;
    if (lio_readb(&io, u32, buffer)) return 1;
    if (memcmp(hello, buffer, sizeof(buffer)) != 0) return 1;
  }

  return close(fd) ? 1 : 0;
}

int main(void)
{
  if (test_writer()) return 1;
  if (test_reader()) return 1;
  return 0;
}
