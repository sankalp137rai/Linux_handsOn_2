#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);

    if(!fork()){
        //inside the child process
        close(STDIN_FILENO);
        fcntl(fd[1],F_DUPFD, STDIN_FILENO);
        close(fd[0]); // closing read end of pipe
        execlp("ls","ls","-l",(char*)NULL);
    }
    else{
        //inside parent process
        close(STDOUT_FILENO);
        //assigned std output 0 to fd[0]
        fcntl(fd[0],F_DUPFD,STDOUT_FILENO);
        close(fd[1]); //closing write end of pipe
        execlp("wc","wc",(char*)NULL);
    }
    // wait(0);
}