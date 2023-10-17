/*
============================================================================
Name : program26.c
Author : Sankalp Rai

Write a program to send messages to the message queue. Check $ipcs -q

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
    printf("Enter the message text: ");
    scanf("%s",myq.message);
    int msgSendStatus = msgsnd(mqid,&myq,sizeof(myq.message)+1, 0);
    if(msgSendStatus == -1){
        perror("Message not send!");
        exit(0);
    }
    return 0;
}