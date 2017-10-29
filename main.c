#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int random_gen(){

	int fd = open("/dev/random", O_RDONLY | O_EXCL);
	if(fd = -1){
		printf("fd: %d\n", fd);
		printf("errno: %d\n", errno);
		printf("error: %s\n", strerror(errno));
	}

	int *buff = (int *)malloc(sizeof(int));
	read(fd, buff, sizeof(int));
	close(fd);
	int ans = *buff;
	free(buff);
	return ans;
}

int main(){
	int random[10];
	int i;
	for(i = 0; i < 10; i++)
		random[i] = random_gen();
	return 0;
}
