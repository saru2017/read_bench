#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <float.h>
#include <stdbool.h>
 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <netdb.h>
 
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <pthread.h>
#include <stdio.h>


#define MAXNUM 10
#define BUFSIZE 1000000

int read_all(char* filename)
{
  char buf[BUFSIZE];
  int fd = open(filename, O_RDONLY);
  int ret;

  while(ret = read(fd, buf, BUFSIZE)){
    printf("read %d bytes\n", ret);
  }

  return 0;
}


long long get_usec_from_tv(struct timeval tv)
{
  long long ret;
  ret = tv.tv_usec + tv.tv_sec * 1000000;

  return ret;
}

int main(int argc, char **argv)
{
  int fd;
  int i;
  char filename[256];
  long long ll_start, ll_end;
  
  struct timeval tv_start, tv_end;

  if(argc != 2){
    printf("%s pathname\n", argv[0]);
    return -1;
  }

  gettimeofday(&tv_start, NULL);
  
  for(i = 0; i < MAXNUM; i++){
    sprintf(filename, "%s/dummy_%04d.dat", argv[1], i);
    read_all(filename);
  }

  gettimeofday(&tv_end, NULL);
  ll_start = get_usec_from_tv(tv_start);
  ll_end = get_usec_from_tv(tv_end);    
  printf("%lld\n", ll_end - ll_start);
}
