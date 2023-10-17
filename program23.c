/*
============================================================================
Name : program23.c
Author : Sankalp Rai

Write a program to print the maximum number of files can be opened within a process and 
size of a pipe (circular buffer).



Date: 10th Sep, 2023.
============================================================================
*/

#include <unistd.h>    
#include <sys/types.h> 
#include <sys/stat.h>  
#include <stdio.h>     
#include <errno.h>     

void main()
{
    int fifoStatus;  
    long maxFiles;
    long sizeOfPipe;

    char *fifoName = "program23_file";
    fifoStatus = mkfifo(fifoName, S_IRWXU);

    if (!(errno == EEXIST || fifoStatus != -1))
        perror("Error while creating FIFO file!");
    else
    {
        maxFiles = sysconf(_SC_OPEN_MAX);

        if (maxFiles == -1)
            perror("Error while calling sysconf!");
        else
            printf("Maximum number of files that can be opened is: %ld\n", maxFiles);

        sizeOfPipe = pathconf(fifoName, _PC_PIPE_BUF);

        if (sizeOfPipe == -1)
            perror("Error while calling pathconf!");
        else
            printf("Maximum size of pipe: %ld\n", sizeOfPipe);
    }
}