/* Augustas Jakaitis IFIN-8/1 */
/* Failas: augjak_pathconf.c */

#include <stdio.h>
#include <unistd.h>

int vp_test();

int vp_test(){
	return 0;
}

int main( int argc, char * argv[] ){
	printf( "(C) 2020 Augustas Jakaitis, %s\n", __FILE__ );
	long path;
	long path1;
	path =  pathconf( ".", _PC_NAME_MAX );
	path1 = pathconf( ".", _PC_PATH_MAX );
	printf( "PC name max yra: %ld \n", path );
	printf( "PC path max yra: %ld \n", path1 );
	return 0;
}
