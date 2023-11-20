#ifndef TETRIS_H
# define TETRIS_H


# include <stdlib.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>
# include <ncurses.h>

# define ROWS 21
# define COLS 16
# define TRUE 1
# define FALSE 0

typedef struct
{
	char **array;
	int width, row, col;
} Shape;

#endif
