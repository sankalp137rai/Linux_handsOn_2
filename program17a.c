#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    int fd[2];
    pipe(fd);

    if(!fork()){
        //inside the child process
        close(1); // closing STD input
        close(fd[0]); // closing read end of pipe
        dup(fd[1]);
        execlp("ls","ls","-l",(char*) NULL);
    }
    else{
        //inside parent process
        close(0); //closinf std output
        close(fd[1]); //closing write end of pipe
        dup(fd[0]); //assigned std output 0 to fd[0]
        execlp("wc", "wc", (char*) NULL);
    }
}