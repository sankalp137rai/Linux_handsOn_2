/*
============================================================================
Name : program27a.c
Author : Sankalp Rai

Write a program to receive messages from the message queue.
 a. with 0 as a flag
 b. with IPC_NOWAIT as a flag

Date: 11th Sep, 2023.
============================================================================
*/


#include<sys/fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    struct msg{
        long int m_type;
        char message[80];
    }myq;

    key_t queuekey = ftok(".",'a');
    int mqid = msgget(queuekey,0);

    printf("Enter the message type: ");
    scanf("%ld",&myq.m_type);
    // printf("Enter the message text: ");
    // scanf("%s",myq.message);

    int msqReceiveStatus = msgrcv(mqid,&myq,sizeof(myq.message)+1,myq.m_type,0);
    if(msqReceiveStatus == -1){
        perror("Message not received!");
        exit(0);
    }
    printf("Message type: %ld\nMessage: %s\n",myq.m_type,myq.message);
    return 0;
}