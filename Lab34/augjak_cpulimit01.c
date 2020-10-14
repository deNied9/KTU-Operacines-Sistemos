#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/resource.h>

/* Augustas Jakaitis IFIN-8/1 augjak */
/* Failas: augjak_aio02.c */

int fileLimit(int nslimit, int nhlimit);

int fileLimit(int nslimit, int nhlimit){
	struct rlimit rl;
	rl.rlim_cur = nslimit;
	rl.rlim_max = nhlimit;
	setrlimit(RLIMIT_CPU, &rl);
	getrlimit(RLIMIT_CORE, &rl);
	printf("Nustatytas cpu limitas %ld s (soft) %ld s (hard)\n", rl.rlim_cur, rl.rlim_max);
	return 1;
}

int main (int argc, char *argv[]){

	printf("(C) 2020 Augustas Jakaitis, %s\n", __FILE__);
	int cnt = 0;
	fileLimit(0, 1);
	while(true){
		cnt++;
	}
	// cnt 31 kartas
	return 0;
}