#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int random_gen(){

	int fd = open("/dev/random", O_RDONLY);
	if(fd == -1){
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
	printf("random:\n");
	for(i = 0; i < 10; i++){
		random[i] = random_gen();
		printf("\trandom[%d]: %d\n", i, random[i]);
	}
	int fd = open("array", O_CREAT | O_RDWR, 0644);
	if(fd == -1){
		printf("fd: %d\n", fd);
		printf("errno: %d\n", errno);
		printf("error: %s\n", strerror(errno));
	}
	write(fd, random, sizeof(random));
	int random2[10];
	read(fd, random2, sizeof(random2));
	printf("random2:\n");
	for(i = 0; i < 10; i++){
		printf("\trandom2[%d]: %d\n", i, random[i]);
	}
	close(fd);
	return 0;
}
