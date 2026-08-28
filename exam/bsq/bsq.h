
#ifndef BSQ_HPP
# define BSQ_HPP
# define ERROR 0
# define SUCCESS 1


#include <stdio.h>

typedef struct s_elements {

	int 	lines;
	char	empty;
	char 	obstacle;
	char 	fill;
} 	Elements;

typedef struct s_map {

	char** 	grid;
	int		x;
	int		y;
} 	Map;

typedef struct s_square {

	int len;
	int	x;
	int	y;
} 	Square;

int run(char* av);
int	execute_bsq(FILE *file);

#endif