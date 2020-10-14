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
/* Failas: augjak_rw01.c */

int failo_atidarymas(const char *name);
int antrasFailo_atidarymas(const char *name);

int antrasFailo_atidarymas(const char *name){

	int fd;
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 664);
	if(fd == -1){
		perror(name);
		exit(1);
	}
	printf("Antras failas tik rasymui sukurtas/isvalytas: %s\n", name);
	return fd;
}

int failo_atidarymas(const char *name){
	
	int fd;
	fd = open(name, O_RDONLY, 444);
	if(fd == -1){
		perror(name);
		exit(1);
	}
	printf("Failas %s atidarytas.\n", name);
	return fd;
}

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

	char buf[dydis];
	int fd, fd2, r, w;

	fd = failo_atidarymas(argv[1]);
	fd2 = antrasFailo_atidarymas(argv[2]);

	r = read(fd, buf, sizeof(buf));
	w = write(fd2, buf, sizeof(buf));

	close(fd);
	close(fd2);

	return 0;
}