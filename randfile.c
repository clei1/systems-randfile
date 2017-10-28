#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd;
    fd = open("/dev/random", O_RDONLY);
    int rand[10];
    read(fd, rand, sizeof(rand));
    close(fd);

    printf("Printing random numbers from /dev/random...\n");
    int i = 10;
    while(i){
        printf("rand[%d]: %d\n", 10 - i, rand[10-i]);
        i --;
    }

    printf("\nWriting to file...\n\n");
    fd = open("foo", O_CREAT | O_WRONLY, 0600);
    write(fd, rand, sizeof(rand));
    close(fd);

    int newrand[10];
    printf("Reading from file...\n");
    fd = open("foo", O_RDONLY);
    read(fd, newrand, sizeof(newrand));

    int d = 10;
    while(d){
        printf("rand[%d]: %d\n", 10 - d, rand[10-d]);
        d --;
    }

    return 0;
}
