/*
============================================================================
Name : program25.c
Author : Sankalp Rai

Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
 a. access permission
 b. uid, gid
 c. time of last message sent and received 
 d. time of last change in the message queue
 d. size of the queue
 f. number of messages in the queue 
 g. maximum number of bytes allowed 
 h. pid of the msgsnd and msgrcv



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
    key_t msgKey;
    int msgId;

    struct msqid_ds msgQueueInfo;
    int msgCtlStatus;

    msgKey = ftok(".",'d');
    if(msgKey == -1){
        perror("Error while creting key");
        _exit(0);
    }
    msgId = msgget(msgKey, IPC_CREAT | 0744);
    if(msgId == -1){
        perror("Error while creating msg queue");
        _exit(0);
    }

    printf("Message Key = %d\t Message Queue ID = %d\n", msgKey, msgId);

    msgCtlStatus = msgctl(msgId, IPC_STAT, &msgQueueInfo);

    if (msgCtlStatus == -1)
    {
        perror("Error while getting Message Queue info!");
        _exit(0);
    }

    printf("Access Permission: %od\n", msgQueueInfo.msg_perm.mode);
    printf("UID: %d\n", msgQueueInfo.msg_perm.uid);
    printf("GID: %d\n", msgQueueInfo.msg_perm.gid);
    printf("Time of last message sent: %ld\n", msgQueueInfo.msg_stime);
    printf("Time of last message received: %ld\n", msgQueueInfo.msg_rtime);
    printf("Size of queue: %ld\n", msgQueueInfo.__msg_cbytes);
    printf("Number of messages in the queue: %ld\n", msgQueueInfo.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n", msgQueueInfo.msg_qbytes);
    printf("PID of last sent message: %d\n", msgQueueInfo.msg_lspid);
    printf("PID of last received message: %d\n", msgQueueInfo.msg_lrpid);

    return 0;
}