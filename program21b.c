#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int mknodStatus1, mknodStatus2;
    int fd1, fd2;
    char buff[100];
    char data[100] = "writting from program2 in file-2";
    char *mknodfile1 = "./mknodfile20a1";
    char *mknodfile2 = "./mknodfile20a2";

    mknodStatus1 = mkfifo(mknodfile2, S_IRWXU);
    mknodStatus2 = mkfifo(mknodfile1, S_IRWXU);
    fd1 = open(mknodfile1, O_WRONLY);
    fd2 = open(mknodfile2, O_RDONLY);

    if(mknodStatus1 == -1){
        perror("error while creating the mknod file1");
    }
    if(fd1==-1){
        perror("error while opening the fifo file-2 for reading");
    }
    else{
        int byteRead = read(fd1,buff, sizeof(buff));
        if(byteRead == -1){
            perror("error while reading file-2");
        }
        printf("Reading the file-2 from program-1: %s", buff);
        close(fd2);
    }
    if(fd2 == -1){
        perror("error while opening the fifo file1 for writing");
    }
    else{
        int writeByte = write(fd1, data, sizeof(data));
        if(writeByte == -1){
            perror("error while writting");
        }
        close(fd1);
    }
    
}