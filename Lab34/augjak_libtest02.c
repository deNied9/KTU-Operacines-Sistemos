#include <stdio.h>
#include <stdlib.h>

/* Augustas Jakaitis IFIN-8/1 augjak */
/* Failas: augjak_libtest02.c */

int augjak_fileLimit(int min, int max);
int augjak_tikrinimai(int count, char *argv[]);

int main(int argc, char *argv[]){
	
	printf("(C) 2020 Augustas Jakaitis, %s\n", __FILE__);

	printf("Vykdoma programa...\n");

	//augjak_fileLimit(0, 1);
	augjak_tikrinimai(argc, argv);

	return 0;
}