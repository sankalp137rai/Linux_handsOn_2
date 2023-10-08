#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int fd[2];
    char buff[80];
    pipe(fd);

    if(fork()){
        //closing read end of pipe in parent
        close(fd[0]);
        printf("write some thing from parent: ");
        scanf("%[^\n]",buff);
        write(fd[1], buff, sizeof(buff));
    }
    else{
        // closing writing end of pipe in childeren
        close(fd[1]);
        read(fd[0], buff, sizeof(buff));
        printf("Message from parent: %s\n",buff);
    }
    wait(0);
}
