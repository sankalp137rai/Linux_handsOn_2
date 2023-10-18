/*
============================================================================
Name : program31a.c
Author : Sankalp Rai

 31. Write a program to create a semaphore and initialize value to the semaphore.
 a. create a binary semaphore
 b. create a counting semaphore

Date: 13th Sep, 2023.
============================================================================
*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/sem.h> 
#include <unistd.h>
#include <stdio.h>  

void main()
{
    key_t semKey;
    int semIndentifier;
    int semctlStatus;

    union semun {
        int val; // Value of the semaphore
    } semSet;

    semKey = ftok(".", 2);
    if (semKey == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    semIndentifier = semget(semKey, 1, IPC_CREAT | 0777);

    if(semIndentifier == -1) {
        perror("Error while creating semaphore!");
        _exit(1);
    }

    semSet.val = 10; // 10 -> counting semaphore

    semctlStatus = semctl(semIndentifier, 0, SETVAL, semSet);

    if(semctlStatus == -1) {
        perror("Error while initalizing semaphore!");
        _exit(0);
    }
}