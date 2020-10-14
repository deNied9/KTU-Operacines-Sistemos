#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Augustas Jakaitis IFIN-8/1 augjak */
/* Failas: augjak_exit01.c */

void functionA(){
	printf("Function - A\n");
}
void functionB(){
	printf("Function - B\n");
}
void functionC(){
	printf("Function - C\n");
}
int main(int argc, char *argv[]){

	printf("(C) 2020 Augustas Jakaitis, %s\n", __FILE__);

	if(argc < 2){
		printf("Iveskite argumentu _Exit, abort, exit, return\n");
		exit(1);

	}
	if(argc > 2){
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
}