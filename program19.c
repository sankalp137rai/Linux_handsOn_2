#include <sys/types.h> // Import for `mkfifo` library function & `mknod` system call
#include <sys/stat.h>  // Import for `mkfifo` library function & `mknod` system call
#include <fcntl.h>     // Import for `mknod` system call
#include <unistd.h>    // Import for `mknod` system call
#include <stdio.h>     //Iport fro using printf and perror

int main(){
    char *mkfifoName = "./mkfifoFile";
    char *mknodeName = "./mknodeName";

    int mkfifoStatus, mknodeStatus;

    mkfifoStatus = mkfifo(mkfifoName, 0744);
    if(mkfifoStatus == -1){
        perror("Error while creating mkfifo file");
    }
    else{
        printf("mkfifo file created succesfully");
    }

    mknodeStatus = mknod(mknodeName, __S_IFIFO, 0744);
    if(mknodeStatus == -1){
        perror("Error while creating mknode file");
    }
    else{
        printf("mknode file created succesfully");
    }
}