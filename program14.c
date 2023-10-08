#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    int i,j,fd[2];
    char buff[80];
    i = pipe(fd);
    printf("i=%d\n", i);
    j = write(fd[1], "writing into the pipe\n",23);
    read(fd[0], buff,j);
    printf("reading from pipe: %s", buff);
    return 0;
}
