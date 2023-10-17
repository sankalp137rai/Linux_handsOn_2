/*
============================================================================
Name : program22a.c
Author : Sankalp Rai
Write a program to wait for data to be written into FIFO within 10 seconds, use select 
system call with FIFO.


Date: 9th Sep, 2023.
============================================================================
*/

#include <sys/types.h> // Import for `open`, `select`
#include <sys/stat.h>  // Import for `open`
#include <fcntl.h>     // Import for `open`
#include <sys/time.h>  
#include <unistd.h>    
#include <stdio.h>     
#include <errno.h>


void main()
{
    int fileDescriptor, writeBytes;
    char data[100];
    char *fifoName = "./program22_file";
    int fifoStatus;

    fifoStatus = mkfifo(fifoName, S_IRWXU);
    if (!(errno == EEXIST || fifoStatus != -1))
        perror("Error while creating FIFO file fifoOne");

    fileDescriptor = open(fifoName, O_NONBLOCK | O_WRONLY);

    if (fileDescriptor == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }

    writeBytes = write(fileDescriptor, "Hello there...", 14);

    if (writeBytes == -1)
        perror("Error while writing to FIFO!");

    close(fileDescriptor);
}