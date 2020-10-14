#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <string.h>

/* Augustas Jakaitis IFIN-8/1 augjak */
/* Failas: augjak_mmap02.c */
int file_open(const char *name, int flag);
int file_close(int fd);

int file_open(const char *name, int flag){

	int fd;
	fd = open(name, flag);
	if(fd == -1){
		perror(name);
		exit(1);
	}
	return fd;

}

int file_close(int fd){
	int rv;
	rv = close(fd);
	if(rv != 0){
		perror("close() failed");
	}else{
		puts("closed");
	}
	return rv;
}

int main(int argc, char *argv[]){

	printf("(C) 2020 Augustas Jakaitis, %s\n", __FILE__);
	if(argc < 2){
		printf("Per mazai argumentu, Ivesk skaitoma faila ir rasoma! \n");
		exit(1);
	}
	if(argc > 3){
		printf("Per daug argumentu, Ivesk skaitoma faila ir rasoma! \n");
		exit(1);
	}
	int skaitymoFailas, rasymoFailas;
	struct stat sb;
	char *skaitomasFailasAtmintyje;
	char *rasomasFailasAtmintyje;
	
	skaitymoFailas = file_open(argv[1], O_RDONLY);
	rasymoFailas = file_open(argv[2], O_RDWR | O_TRUNC);

	if(fstat(skaitymoFailas, &sb) == -1){
		perror("couldnt get file size");
	}
	printf("Skaitomo failo dydis: %ld\n", sb.st_size);

	skaitomasFailasAtmintyje = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, skaitymoFailas, 0);
	ftruncate(rasymoFailas, sb.st_size);
	rasomasFailasAtmintyje = mmap(NULL, sb.st_size, PROT_WRITE, MAP_SHARED, rasymoFailas, 0);

	memcpy(rasomasFailasAtmintyje, skaitomasFailasAtmintyje, sb.st_size);

	//memcpy(&rasymoFailas, skaitomasFailasAtmintyje, sb.st_size);
	munmap(skaitomasFailasAtmintyje, sb.st_size);
	munmap(rasomasFailasAtmintyje, sb.st_size);

	file_close(skaitymoFailas);
	file_close(rasymoFailas);

	return 0;
}