#include "life.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	print_game(Game *game) {

	for (int i = 0; i < game->heigth; i++) {

		for (int j = 0; j < game->width; j++) {

			putchar(game->map[i][j]);
		}
		putchar('\n');
	}
}

void	free_game(char** grid) {

	if (grid) {

		int i = 0;
		while(grid[i]) {

			if(grid[i])
				free(grid[i]);
			i++;
		}
		free(grid);
	}
}

int	init_game(Game *game, char** av) {

	game->width = atoi(av[1]);
	game->heigth = atoi(av[2]);
	game->iterations = atoi(av[3]);
	game->x = 0;
	game->y = 0;
	game->alive = 'O';
	game->dead = ' ';
	game->draw = false;

	game->map = calloc(game->heigth + 1, sizeof(char*));
	if (!game->map)
		return ERROR;

	for (int i = 0; i < game->heigth; i++) {

		game->map[i] = calloc((game->width + 1), sizeof(char));
		if (!game->map[i]) {
			free_game(game->map);
			return ERROR;
		}

		for (int j = 0; j < game->width; j++) {

			game->map[i][j] = ' ';
		}
	}
	return SUCCESS;
}

int	fill_game(Game *game) {

	char buffer;
	int flag = 0;

	while(read(STDIN_FILENO, &buffer, 1) == 1) {

		switch (buffer) {

			case 'w':
				if (game->y > 0)
					game->y--;
				break;
			case 's':
				if (game->y < game->heigth - 1)
					game->y++;
				break;
			case 'a':
				if (game->x > 0)
					game->x--;
				break;
			case 'd':
				if (game->x < game->width - 1)
					game->x++;
				break;
			case 'x':
				game->draw = !game->draw;
				break;
			default:
				flag = 1;

		}
		if (game->draw && flag == 0) {

			if ((game->y >= 0) && (game->x >= 0) && (game->y < game->heigth) && (game->x < game->width))
				game->map[game->y][game->x] = game->alive;
 		}
	}
	return SUCCESS;
}

int	count_neighbours(Game *game, int i, int j) {

	int count = 0;
	for (int di = -1; di < 2; di++) {

		for(int dj = -1; dj < 2; dj++) {

			if (dj == 0 && di == 0)
				continue;

			int ni = i - di;
			int nj = j - dj;

			if ((ni >= 0) && (nj >= 0) && (ni < game->heigth) && (nj < game->width))
				if (game->map[ni][nj] == game->alive)
					count++;
		}
	}
	return count;
}

int	start_simulation(Game *game) {

	char** tmp = calloc(game->heigth + 1, sizeof(char*));
	if(!tmp)
		return ERROR;
	for (int i = 0; i < game->heigth; i++) {

		tmp[i] = calloc(game->width + 1, sizeof(char));
		if (!tmp[i]) {

			free_game(tmp);
			return ERROR;
		}
	}

	for(int i = 0; i < game->heigth; i++) {

		for(int j = 0; j < game->width; j++) {

			int neighbour = count_neighbours(game, i , j);
			if (game->map[i][j] == game->alive) {

				if (neighbour == 2 || neighbour == 3)
					tmp[i][j] = game->alive;

				else
					tmp[i][j] = game->dead;
			}
			else
			{
				if (neighbour == 3)
					tmp[i][j] = game->alive;
				else
					tmp[i][j] = game->dead;
			}
		}
	}

	free_game(game->map);
	game->map = tmp;
	return SUCCESS;
}

int main(int ac, char** av){

	if (ac != 4)
		return 1;

	Game game;
	if (!init_game(&game, av))
		return 1;

	if(!fill_game(&game))
		return 1;

	for(int i = 0; i < game.iterations; i++) {

		if(!start_simulation(&game)) {
			free_game(game.map);
			return ERROR;
		}
	}
	print_game(&game);
	free_game(game.map);


	return 0;

}