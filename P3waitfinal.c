#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    printf(" P3: Demonstration of WAIT() System Call\n\n");
    printf(" NAME: Ayush Ramola | SECTION: C (G1) | ROLL NUMBER: 17\n\n");
    pid_t child_pid = fork();
    if(child_pid == 0){
        printf(" I am the child process with PID = %d\n", getpid());
        printf(" My parent is now waiting with parent PID: %d. \n\n", getppid());
        sleep(4);
        exit(0);
    }else if(child_pid > 0){
        printf(" I am the parent process and my PID is %d \n", getpid());
        printf(" and my child is: %d \n", child_pid);
        int waiting_pid = wait(NULL);
        printf(" My child has been terminated with PID %d \n", waiting_pid);
    }
    return 0;
}
