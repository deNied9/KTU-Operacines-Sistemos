#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

/* Augustas Jakaitis IFIN-8/1 augjak */
/* Failas: augjak_dynload02.c */

int (*fptr)(int min, int max);

int main(int argc, char *argv[]){
	
	printf("(C) 2020 Augustas Jakaitis, %s\n", __FILE__);

	void *dl;

	printf("Vykdoma programa...\n");

	dl = dlopen("lib/augjak02a.so", RTLD_LAZY | RTLD_LOCAL | RTLD_NOW);
	*(void **)(&fptr) = dlsym(dl, "augjak_fileLimit");
	*(void **)(0, 1);

	//neveikia 

	return 0;
}