

#include "bsq.h"
#include <stdio.h>

int main(int ac, char** av) {

	if (ac == 1) {

		if(execute_bsq(stdin) == ERROR) {

			fprintf(stderr, "map error\n");
			return 1;
		}
	}

	else {

		for (int i = 1; i < ac; i++) {

			if(!run(av[i]))
				fprintf(stderr, "map error\n");
			if (ac > 2 && ac - 1 != i)
				fprintf(stdout, "\n");
		}
	}
	return 0;
}