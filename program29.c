/*
============================================================================
Name : program28.c
Author : Sankalp Rai

Write a program to remove the message queue.

Date: 12th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t msgKey;
    int msgQueueID;
    
    msgKey = ftok(".", 'c');

    if (msgKey == -1) {
        perror("ftok");
        exit(1);
    }

    // Access the message queue
    msgQueueID = msgget(msgKey, 0);

    if (msgQueueID == -1) {
        perror("msgget");
        exit(1);
    }

    // Remove the message queue using IPC_RMID
    if (msgctl(msgQueueID, IPC_RMID, NULL) == -1) {
        perror("msgctl (IPC_RMID)");
        exit(1);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}