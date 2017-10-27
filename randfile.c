#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

  int fd;
  fd = open("/dev/random", O_RDONLY);
  int rand[10];
  read(fd, rand, sizeof(rand));
  close(fd);

  int i = 10;
  while(i){
    printf("%d\n", rand[10-i]);
    i --;
  }
  

  fd = open("foo", O_CREAT | O_RDWR, 0600);
  write(fd, rand, sizeof(rand));
  int newrand[10];
  read(fd, newrand, sizeof(newrand));

  int d = 10;
  while(d){
    printf("%d\n", newrand[10-d]);
    d --;
  }
  
  
  close(fd);


  
  return 0;
}
