#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FileName "data.dat"
#define DataString "Do not go gentle into that good night\nbut rage, rage against the dying of the light.\n"

void report_and_exit(const char* msg) {
  perror(msg);
  exit(-1); /* EXIT_FAILURE */
}

int main() {

  /* declare and define a standard library lock */
  struct flock lock = {
    F_WRLCK,  /* l_type: read/write (exclusive versus shared) lock */
    SEEK_SET, /* l_whence: base for seek offsets */
    0,        /* l_start: 1st byte in file */
    0,        /* l_len: 0 here means 'until EOF' */
    getpid()  /* l_pid: process id */
  };

  /* the file descriptor identifies a file within a process.
   * It creates the file if it doesn't exist already. */
  int fd = open(FileName, O_RDWR | O_CREAT, 0666);

  /* check if the file has been created/opened */
  if (fd < 0) {
    /* -1 signals an error */
    report_and_exit("open failed...");
  }

  /* get an exclusive lock for writing operation */
  if (fcntl(fd, F_SETLK, &lock) < 0) {
    /* F_SETLK doesn't block, F_SETLKW does **/
    report_and_exit("fcntl failed to get lock...");
  }
  else {
    /* success getting the exclusive lock */
    write(fd, DataString, strlen(DataString)); /* populate data file */
    fprintf(stderr, "Process %d has written to data file...\n", lock.l_pid);
  }

  /* Now release the lock explicitly. */
  lock.l_type = F_UNLCK;
  if (fcntl(fd, F_SETLK, &lock) < 0) {
    report_and_exit("explicit unlocking failed...");
  }

  close(fd); /* close the file: would unlock if not released successfully before */
  return 0;  /* terminating the process would unlock as well */
}
