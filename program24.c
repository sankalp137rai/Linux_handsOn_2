/*
============================================================================
Name : program24.c
Author : Sankalp Rai

. Write a program to create a message queue and print the key and message queue id



Date: 10th Sep, 2023.
============================================================================
*/

#include<sys/fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>
#include<stdio.h>

int main(){
    key_t key;
    int msgId;

    key = ftok(".",'b');
    if(key == -1){
        perror("Error while creting key");
        _exit(0);
    }
    msgId = msgget(key, IPC_CREAT | IPC_EXCL|0744);
    if(msgId == -1){
        perror("Error while creating msg queue");
        _exit(0);
    }
    printf("Key = %d\t msgId=%d\n", key, msgId);
    return 0;
}