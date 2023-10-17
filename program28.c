/*
============================================================================
Name : program28.c
Author : Sankalp Rai

Write a program to change the exiting message queue permission. (use msqid_ds structure)

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
    struct msqid_ds msgQueueInfo;
    key_t queuekey = ftok(".",'a');
    int mqid = msgget(queuekey,O_CREAT | 0700);

    int msqCtrlStatus = msgctl(mqid, IPC_STAT, &msgQueueInfo);
    if(msqCtrlStatus == -1){
        perror("Message  control not received!");
        exit(0);
    }
    msgQueueInfo.msg_perm.mode = 0644; // Change the permissions to rw-r--r--

    // Set the new permissions using IPC_SET
    if (msgctl(mqid, IPC_SET, &msgQueueInfo) == -1) {
        perror("msgctl (IPC_SET)");
        exit(1);
    }
    return 0;
}