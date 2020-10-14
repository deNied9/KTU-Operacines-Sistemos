/* Augustas Jakaitis IFIN-8/1 */
/* Failas: augjak_readdir01.c */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>

int test_opendir();

int test_opendir(){
	int fd;
	int fdr;
	DIR *folder;
	struct dirent *dp;
	/* fd = open(".", O_RDONLY);
	folder = fdopendir(fd); */
	folder = opendir(".");
	if(folder == NULL)
	{
		puts("Neina perskaityt");
		return(1);
	}
	else
	{
		
		puts("Directory open");
		while ((dp = readdir(folder)) != NULL)
		{
			printf("i-node: %ld | failo vardas: %s \n", dp->d_ino, dp->d_name);
		}
	}
	closedir(folder);
	return 0;
}

int main( int argc, char * argv[] ){
	printf( "(C) 2020 Augustas Jakaitis, %s\n", __FILE__ );
	test_opendir();
	return 0;
}
