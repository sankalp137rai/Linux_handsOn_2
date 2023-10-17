/*
============================================================================
Name : program22a.c
Author : Sankalp Rai
Write a program to wait for data to be written into FIFO within 10 seconds, use select 
system call with FIFO.


Date: 9th Sep, 2023.
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <sys/time.h> 
#include <unistd.h>    
#include <stdio.h>     
#include <errno.h>

void main()
{
    int fileDescriptor, readBytes;
    char data[100];

    fd_set readFDSet;
    struct timeval timer;
    int selectStatus;

    char *fifoName = "./program22_file";
    int fifoStatus;

    fifoStatus = mkfifo(fifoName, S_IRWXU);
    if (!(errno == EEXIST || fifoStatus != -1))
        perror("Error while creating FIFO file fifoOne");

    fileDescriptor = open(fifoName, O_NONBLOCK | O_RDONLY);

    if (fileDescriptor == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }

    FD_ZERO(&readFDSet);
    FD_SET(fileDescriptor, &readFDSet); // Adding FIFO file's descriptor to the set of file descriptors to read from

    // Setting the time to wait to 10s
    timer.tv_sec = 10;
    timer.tv_usec = 0;

    selectStatus = select(fileDescriptor + 1, &readFDSet, NULL, NULL, &timer);

    if (selectStatus == -1)
        perror("Error while calling for select!");
    else if (selectStatus)
    {
        readBytes = read(fileDescriptor, &data, 100);

        if (readBytes == -1)
            perror("Error while reading from FIFO!");
        else
            printf("Data received : %s\n", data);
    }
    else
        printf("You didn't send any data for 10 seconds! :(\n");

    close(fileDescriptor);
}