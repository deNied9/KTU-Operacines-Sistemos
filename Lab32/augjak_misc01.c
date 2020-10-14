/* Augustas Jakaitis IFIN-8/1 */
/* Failas: augjak_misc01.c */

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

int rn(const char *path1, const char *path2);

int rn(const char *path1, const char *path2){
	int r;
	r = rename(path1, path2);
	return 0;
}

int main( int argc, char * argv[] ){
	printf( "(C) 2020 Augustas Jakaitis, %s\n", __FILE__ );
	printf("Rename() funckcija iveskite 2 path\n");
	int r;
	r = rn(argv[1], argv[2]);
	printf("Pirmo failo name: %s\n", argv[1]);
	printf("Renamed failas: %s\n", argv[2]);
	return 0;
}
