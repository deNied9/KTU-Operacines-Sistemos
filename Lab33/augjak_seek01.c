#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Augustas Jakaitis IFIN-8/1 augjak */
/* Failas: augjak_seek01.c */


int main(int argc, char *argv[]){
	
	printf("(C) 2020 Augustas Jakaitis, %s\n", __FILE__);

	if(argc > 1){
		printf("Nereikia argumentu\n");
		exit(1);
	}

	char buf[1];
	int fd, w;
	char *failoName = "1MB_failas";
	fd = open(failoName, O_RDWR | O_CREAT, 0666);

	if(fd == -1){
		perror("name");
		exit(1);
	}
	
	printf("Sukurtas failas: %s\n", failoName);

	lseek(fd, (1024*1024), SEEK_SET);
	w = write(fd, buf, 1);

	if(w == -1){
		perror("name");
		exit(1);
	}

	close(fd);
	close(w);
	return 0;
}