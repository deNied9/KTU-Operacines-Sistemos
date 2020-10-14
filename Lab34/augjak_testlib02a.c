#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/resource.h>
#include "augjak_testlib02.h"

/* Augustas Jakaitis IFIN-8/1 augjak */
/* Failas: augjak_testlib02a.c */

int augjak_fileLimit(int nslimit, int nhlimit){

	printf("(C) 2020 Augustas Jakaitis, %s\n", __FILE__);

	struct rlimit rl;
	rl.rlim_cur = nslimit;
	rl.rlim_max = nhlimit;
	setrlimit(RLIMIT_CPU, &rl);
	getrlimit(RLIMIT_CORE, &rl);
	printf("Nustatytas cpu limitas %ld s (soft) %ld s (hard)\n", rl.rlim_cur, rl.rlim_max);
	return 0;
}