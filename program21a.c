/*
============================================================================
Name : program21a.c
Author : Sankalp Rai
Write two programs so that both can communicate by FIFO -Use two way communications.

Date: 9th Sep, 2023.
============================================================================
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int mknodStatus1, mknodStatus2;
    int fd1,fd2;
    char data[] = "writing to file1 by program-1!!";
    char buff[100]; // buffer for reading the data from file 2
    char *mknodfile1 = "./mknodfile21a1"; // for wriiting data
    char *mknodfile2 = "./mknodfile21a2"; // for reading from other process;
    mknodStatus1 = mkfifo(mknodfile1, S_IRWXU);
    mknodStatus2 = mkfifo(mknodfile1, S_IRWXU);
    fd1 = open(mknodfile1, O_WRONLY);
    fd2 = open(mknodfile2, O_RDONLY);
    if(mknodStatus1 == -1){
        perror("error while creating the mknod file");
    }
    if(fd1 == -1){
        perror("error while opening the fifo file1 for writing");
    }
    else{
        int writeByte = write(fd1, data, sizeof(data));
        if(writeByte == -1){
            perror("error while writting");
        }
        close(fd1);
    }
    if(fd2==-1){
        perror("error while opening the fifo file-2 for reading");
    }
    else{
        int byteRead = read(fd2,buff, sizeof(buff));
        if(byteRead == -1){
            perror("error while reading file-2");
        }
        printf("Reading the file-2 from program-1: %s", buff);
        close(fd2);
    }
}