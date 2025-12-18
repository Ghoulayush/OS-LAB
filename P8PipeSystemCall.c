#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf(" NAME: Ayush | SECTION: C (G1) | ROLL NUMBER: 17\n\n");
  int fd[2];
  pid_t p;
  char write_msg[] = "Hello from parent!";
  char read_msg[100];
  if (pipe(fd) == -1) {
    perror("pipe");
    return 1;
  }
  p = fork();
  if (p < 0) {
    perror("fork");
    return 1;
  }
  if (p > 0) {
    close(fd[0]);
    write(fd[1], write_msg, strlen(write_msg) + 1);
    close(fd[1]);
  } else {
    close(fd[1]);
    read(fd[0], read_msg, sizeof(read_msg));
    printf("Child received: %s\n", read_msg);
    close(fd[0]);
  }
  return 0;
}
