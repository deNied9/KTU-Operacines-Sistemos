#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <aio.h>
#include <time.h>

/* Augustas Jakaitis IFIN-8/1 augjak */
/* Failas: augjak_aio02.c */

int file_open(const char *name);
int file_close(int fd);
int aio_read_start(const int d, struct aiocb *aiorp, void *buf, const int length);
int aio_wait_complete(struct aiocb *aiorp);
int aio_write_start(const int d, struct aiocb *aiorp, void *buf, const int length);

int file_open(const char *name){
	int fd;
	fd = open( name, O_RDONLY );
	if(fd == -1){
		perror(name);
		exit(1);
	}
	return fd;
}

int file_close(int fd){
	int rv;
	rv = close( fd );
	if(rv != 0){
		perror( "close() failed" );
	}else{
		puts( "closed" );
	}
	return rv;
}



int aio_read_start(const int d, struct aiocb *aiorp, void *buf, const int length){

	int aioRead = 0;
	memset( (void *)aiorp, 0, sizeof( struct aiocb) );

	aiorp->aio_fildes = d;
	aiorp->aio_buf = buf;
	aiorp->aio_nbytes = length;
	aiorp->aio_offset = 0;

	aioRead = aio_read( aiorp );

	if(aioRead != 0){
		perror("aio_read failed");
		abort();
	}
	return aioRead;
}

int aio_write_start(const int d, struct aiocb *aiorp, void *buf, const int length){
	int aioWrite = 0;
	memset( (void *)aiorp, 0, sizeof( struct aiocb) );

	aiorp->aio_fildes = d;
	aiorp->aio_buf = buf;
	aiorp->aio_nbytes = length;
	aiorp->aio_offset = 0;

	aioWrite = aio_write( aiorp );
	if(aioWrite != 0){
		perror("aio_write failed");
		abort();
	}
	return aioWrite;
}

int aio_wait_complete(struct aiocb *aiorp){

	const struct aiocb *aioptr[1];
	int rv;
	aioptr[0] = aiorp;
	rv = aio_suspend(aioptr, 1, NULL);
	if(rv != 0){
		perror("aio_suspend failed");
	}
	rv = aio_return(aiorp);
	printf("AIO completed, %d bytes read.\n", rv);
	return 1;
}

int main(int argc, char *argv[]){
	printf("(C) 2020 Augustas Jakaitis, %s\n", __FILE__);

	if(argc < 2){
		printf("Iveskite failo varda i kuri rasysite duomenis\n");
		exit(1);
	}

	int fd, fw, aio, aio2;
	struct aiocb aior;
	char buff[1024*1024];

	fd = file_open("/dev/random");

	aio = aio_read_start(fd, &aior, buff, sizeof(buff));

	fw = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if(fw == -1){
		perror("name");
		exit(1);
	}

	aio2 = aio_write_start(fw, &aior, buff, sizeof(buff));
	aio_wait_complete(&aior);
	aio = aio_read_start(fd, &aior, buff, sizeof(buff));
	aio2 = aio_write_start(fw, &aior, buff, sizeof(buff));

	file_close(fd);
	file_close(fw);
	printf("Aio uzdarytas %d\n", sizeof(buff));

	//Nesu tikras ar teisingai supratau salyga
	
	return 0;
}