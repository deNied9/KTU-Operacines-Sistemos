/* Augustas Jakaitis IFIN-8/1 */
/* Failas: augjak_nftw02.c */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/statvfs.h>
#include <ftw.h>
#include <dirent.h>

int display(const char *fpath, const struct stat *sbuf, int type, struct FTW *ftwb);

int display(const char *fpath, const struct stat *sbuf, int type, struct FTW *ftwb){
	const char *const filename = fpath + ftwb->base;
	if (type == FTW_NS){perror( "netinkamas formatas" );}
	printf("Lygis %d: %s \n", ftwb->level, filename);
	return 0;
}

int main( int argc, char * argv[] ){
	printf( "(C) 2020 Augustas Jakaitis, %s\n", __FILE__ );
	int vaiksto;
	int flag = FTW_PHYS;
	vaiksto = nftw( argv[1], display, 20, flag );
	if(vaiksto == -1){
		perror( "ntfw failed" );
		exit(EXIT_FAILURE);
	}	
	return 0;
}
