#ifndef LIFE_HPP
# define LIFE_HPP

#define ERROR 0;
#define SUCCESS 1;

#include <stdbool.h>

typedef struct game {

	int 	x;
	int 	y;
	int 	width;
	int 	heigth;
	int 	iterations;
	char 	alive;
	char 	dead;
	char 	**map;
	bool	draw;

} Game;

#endif

