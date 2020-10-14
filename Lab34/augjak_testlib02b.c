#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "augjak_testlib02.h"

/* Augustas Jakaitis IFIN-8/1 augjak */
/* Failas: augjak_testlib02b.c */

void functionA(){
	printf("Function - A\n");
}
void functionB(){
	printf("Function - B\n");
}
void functionC(){
	printf("Function - C\n");
}
int augjak_tikrinimai(int count, char *argv[]){

	printf("(C) 2020 Augustas Jakaitis, %s\n", __FILE__);

	if(count < 2){
		printf("Iveskite argumentu _Exit, abort, exit, return\n");
		exit(1);

	}
	if(count > 2){
		printf("Per daug argumentu\n");
		exit(1);
	}
	atexit(functionA);
	atexit(functionB);
	atexit(functionC);
	if(!strcmp(argv[1], "_Exit")){
		_Exit(0);
	}
	if(!strcmp(argv[1], "abort")){
		abort();
	}
	if(!strcmp(argv[1], "exit")){
		exit(0);
	}
	if(!strcmp(argv[1], "return")){
		return 0;
	}
	printf("Starting main...\n");
	printf("Exiting main...\n");

	return 0;
}