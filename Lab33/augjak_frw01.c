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
/* Failas: augjak_frw01.c */

int main(int argc, char const *argv[]){
	
	printf("(C) 2020 Augustas Jakaitis, %s\n", __FILE__);


	if(argc < 1){
		perror("name");
		exit(1);
	}

	char *p;
	errno = 0;
	long dydis = strtol(argv[3], &p, 10);
	if(*p != '\0' || errno != 0){
		printf("Paskutinis argumentas turi buti skaicius\n");
		return 1;
	}

	void *buf[dydis];
	size_t r, w;
	int f1, f2;
	FILE *fd;
	FILE *fd2;

	fd = fopen(argv[1], "r");
	if(fd == NULL){
		perror("name");
		exit(1);
	}
	printf("Failas %s atidarytas.\n", argv[1]);

	fd2 = fopen(argv[2], "w");
	if(fd2 == NULL){
		perror("name");
		exit(1);
	}
	printf("Antras failas tik rasymui sukurtas/isvalytas: %s\n", argv[2]);

	r = fread(buf, sizeof(buf), 1, fd);
	w = fwrite(buf, sizeof(buf), 1, fd2);

	f1 = fclose(fd);
	f2 = fclose(fd2);

	return 0;
}