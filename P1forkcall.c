#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    printf(" P1: Demonstration of FORK() System Call\n");
    printf(" NAME: Ayush Ramola | SECTION: C (G1) | ROLL NUMBER: 17\n\n");
    pid_t processID = fork();
    if (processID == 0){
        printf(" This is the child process. pid: %d\n", getpid());
    }
    else{
        printf(" This is the parent process with PID: %d\n", getpid());
        printf(" Child PID: %d\n", processID);
    }
    return 0;
}
