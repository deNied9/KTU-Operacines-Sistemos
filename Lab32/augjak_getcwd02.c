/* Augustas Jakaitis IFIN-8/1 */
/* Failas: augjak_getcwd02.c */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int vp_test();
int test_getcwd();

int test_getcwd(){
	/*char *cwd;*/
	char *buf;
	char *cwd2;
	int fd, rv;
	buf = malloc(sizeof(char));
	cwd2 = getcwd( buf, pathconf( ".", _PC_PATH_MAX ) );
	/*cwd = getcwd( NULL, pathconf( ".", _PC_PATH_MAX ) );*/
	printf( "Po getcwd metodo: %s\n", cwd2 );
	
	fd = open( cwd2, O_RDONLY );
	printf( "Open metodas: %d\n", fd);
	
	char *fs = "/tmp";
	int ch, fh;
	char *cwd, *cwd3;
	
	ch = chdir(fs);
	
	cwd = getcwd( NULL, pathconf( ".", _PC_PATH_MAX ) );
	printf( "Po chdir metodo dabartinis katalogas: %s\n", cwd);
	
	fh = fchdir( fd );
	cwd3 = getcwd( NULL, pathconf( ".", _PC_PATH_MAX ) );
	printf( "Tikrinimas fchdir ar grizoma i 2-amze zingsnyje nurodyta kataloga: \n" ); 
	
	puts( cwd3 );
	free( cwd3 );
	
	rv = close( fd );
	
	return 0;
}

int vp_test(){
	return 0;
}

int main( int argc, char * argv[] ){

	printf( "(C) 2020 Augustas Jakaitis, %s\n", __FILE__ );
	test_getcwd();
	return 0;
}
