/* Augustas Jakaitis IFIN-8/1 */
/* Failas: augjak_statvfs.c */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/statvfs.h>


int main( int argc, char * argv[] ){
	printf( "(C) 2020 Augustas Jakaitis, %s\n", __FILE__ );
	int id;
	struct stat sb;
	id = stat(argv[1], &sb);
	if (id == -1){
		perror("stat");
		exit(EXIT_FAILURE);
	}
	printf("Savininko ID: %d\n", sb.st_uid);
	printf("Failo dydis: %ld\n", sb.st_size);
	printf("i-node numeris: %ld\n", sb.st_ino);
	printf("Failo leidimai: ");
    printf( (S_ISDIR(sb.st_mode)) ? "d" : "-");
    printf( (sb.st_mode & S_IRUSR) ? "r" : "-");
    printf( (sb.st_mode & S_IWUSR) ? "w" : "-");
    printf( (sb.st_mode & S_IXUSR) ? "x" : "-");
    printf( (sb.st_mode & S_IRGRP) ? "r" : "-");
    printf( (sb.st_mode & S_IWGRP) ? "w" : "-");
    printf( (sb.st_mode & S_IXGRP) ? "x" : "-");
    printf( (sb.st_mode & S_IROTH) ? "r" : "-");
    printf( (sb.st_mode & S_IWOTH) ? "w" : "-");
    printf( (sb.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
	printf("Failo tipas: ");
	if (S_ISREG(sb.st_mode)) {
		
		printf("failas ");
		/*Neveikia kazkodel*/
		if (S_ISLNK(sb.st_mode)) {printf("simbolinis linkas");}
		if (S_ISCHR(sb.st_mode)) {printf("character device");}
		if (S_ISBLK(sb.st_mode)) {printf("block device");}
		if (S_ISFIFO(sb.st_mode)) {printf("kanalas");}
		if (S_ISSOCK(sb.st_mode)) {printf("socketas");}
		
	}
	if (S_ISDIR(sb.st_mode)) {printf("katalogas");}
	
	printf("\n\n");

	printf("statvfs() ir fstatvfs() \n");
	int vfs;
	struct statvfs buf;
	vfs = statvfs(argv[1], &buf);
	printf("Failu sistemos bloko dydis: %ld\n", buf.f_bsize);
	printf("Failu sistemos ID: %ld\n", buf.f_fsid);
	printf("Failu sistemo dydid: %ld\n", buf.f_frsize);
	printf("Maksimalus failo kelio/vardo ilgis: %ld\n", buf.f_namemax);
	
	return 0;
}
