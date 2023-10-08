#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    //for parent to read and child to write
    int fd1[2];
    //for child to read and parnet to write
    int fd2[2];
    char buff1[80], buff2[80];
    pipe(fd1);
    pipe(fd2);
    if(fork()){
        //Inside parent
        close(fd1[1]);
        close(fd2[0]);
        printf("Enter msg to child: ");
        scanf("%[^\n]",buff1);
        write(fd2[1], buff1, sizeof(buff1));
        read(fd1[0],buff2,sizeof(buff2));
        printf("Reading the child msg: %s \n", buff2);
    }
    else{
        close(fd1[0]);
        close(fd2[1]);
        read(fd2[0],buff1,sizeof(buff1));
        printf("Reading the parent msg: %s \n", buff1);
        printf("Enter msg to parent: ");
        scanf("%[^\n]",buff2);
        write(fd1[1],buff2,sizeof(buff2));
    }
    wait(0);
}