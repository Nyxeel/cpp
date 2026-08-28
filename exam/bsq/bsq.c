

#include "bsq.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int	load_elements(FILE *file, Elements *elements) {

	int ret = fscanf(file, "%d %c %c %c", &elements->lines, &elements->empty, &elements->obstacle, &elements->fill);
	if (ret != 4)
		return ERROR;

	if (elements->lines <= 0)
		return ERROR;

	if (elements->empty == elements->obstacle || elements->obstacle == elements->fill || elements->fill == elements->empty)
		return ERROR;
	if (elements->empty < 32 || elements->empty > 126)
		return ERROR;
	if (elements->obstacle < 32 || elements->obstacle > 126)
		return ERROR;
	if (elements->fill < 32 || elements->fill > 126)
		return ERROR;

	return SUCCESS;
}

void	free_grid(char** grid) {

	if (grid) {

		int i = 0;
		while (grid[i]) {

			if (grid[i])
				free(grid[i]);
			i++;
		}
		free(grid);
	}
}


char*	ft_substr(char *str, int start, int len) {


	char* substr = calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	if (start > len)
		return (free(substr), NULL);
	int i = 0;
	while (str[start + i] && i < len ) {
		substr[i] = str[start + i];
		i++;
	}
	return substr;
}


int check_map_elements(char** map, Elements *elements, int height, int len) {

	if (len == 0)
		return ERROR;
	for (int i = 0; i < height; i++) {

		for (int j = 0; j < len; j++){

			if (map[i][j] != elements->empty && map[i][j] != elements->obstacle) {
				return ERROR;
			}
		}
	}
	return SUCCESS;
}

int	load_map(FILE *file, Map *map, Elements *elements) {

	map->x = 0;
	map->y = elements->lines;
	map->grid = calloc(map->y + 1, sizeof(char*));
	if (!map->grid)
		return ERROR;


	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, file) == -1) {

		free_grid(map->grid);
		return ERROR;
	}


	for(int i = 0; i < map->y; i++) {

		int read = getline(&line, &len, file);
		if (read == -1){

			free(line);
			free_grid(map->grid);
			return ERROR;
		}

		if (line[read - 1] == '\n')
			read--;


		map->grid[i] = ft_substr(line, 0, read);
		if (!map->grid[i]) {
			free(line);
			free_grid(map->grid);
			return ERROR;
		}
		if (i == 0)
			map->x = read;
		else
		{

			if (map->x != read) {
				free(line);
				free_grid(map->grid);
				return ERROR;
			}
		}

	}
	free(line);

	if (!check_map_elements(map->grid, elements, map->y, map->x)) {
		free_grid(map->grid);
		return ERROR;
	}

	return SUCCESS;

}

int	find_min(int num1, int num2, int num3) {

	int min = num1;
	if (num2 < min)
		min = num2;
	if (num3 < min)
		min = num3;
	return min;
}


void find_biggest_square(Map *map, Elements *elements, Square *quadr) {

	int matrix[map->y][map->x];

	for (int i = 0; i < map->y; i++) {

		for (int j = 0; j < map->x; j++) {

			if (map->grid[i][j] == elements->obstacle)
				matrix[i][j] = 0;
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			else {

				int min = find_min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
				matrix[i][j] = min + 1;
			}

			if (matrix[i][j] > quadr->len) {

				quadr->len = matrix[i][j];
				quadr->y = i - quadr->len + 1;
				quadr->x = j - quadr->len + 1;
			}
		}
	}
}


void	print_map(Square *quadr, Map *map, Elements *elements) {

	for (int i = quadr->y; i < quadr->y + quadr->len; i++) {

		for (int j = quadr->x; j < quadr->x + quadr->len; j++) {

			if((i < map->y) && (j < map->x))
				map->grid[i][j] = elements->fill;
		}
	}
	int i = 0;
	while(map->grid[i]) {

		fprintf(stdout, "%s\n", map->grid[i]);
		i++;
	}

}


int	execute_bsq(FILE *file) {

	Elements elements;

	if(!load_elements(file, &elements))
		return ERROR;

	Map map;
	if(!load_map(file, &map, &elements))
		return ERROR;

	Square quadr;

	quadr.len = 0;
	quadr.x = 0;
	quadr.y = 0;

	find_biggest_square(&map, &elements, &quadr);
	print_map(&quadr, &map, &elements);
	free_grid(map.grid);
	return SUCCESS;
}

int run(char* name) {

	FILE *file = fopen(name, "r");
	if (!file) {
		return ERROR;
	}

	if (!execute_bsq(file)) {

		fclose(file);
		return ERROR;
	}
	fclose(file);
	return SUCCESS;
}

