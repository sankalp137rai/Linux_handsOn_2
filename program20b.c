#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int mknodStatus;
    int fd;
    char buff[100];
    char *mknodfile = "./mknodfile20a";
    fd = open(mknodfile, O_RDONLY);
    if(fd == -1){
        perror("error while reading the fifo file");
    }
    else{
        int readByte = read(fd, buff, sizeof(buff));
        if(readByte == -1){
            perror("error while writting");
        }
        else{
            printf("ReadByte: %d\n", readByte);
            printf("Data from FIFO file: %s\n",buff);
        }
        close(fd);
    }
}