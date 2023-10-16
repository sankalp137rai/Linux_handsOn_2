#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int mknodStatus;
    int fd;
    char data[] = "writing to file!!";
    char *mknodfile = "./mknodfile20a";
    mknodStatus = mkfifo(mknodfile, S_IRWXU);
    fd = open(mknodfile, O_WRONLY);
    if(mknodStatus == -1){
        perror("error while creating the mknod file");
    }
    if(fd == -1){
        perror("error while opening the fifo file");
    }
    else{
        int writeByte = write(fd, data, sizeof(data));
        if(writeByte == -1){
            perror("error while writting");
        }
        close(fd);
    }
}
