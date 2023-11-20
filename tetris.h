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

char Table[ROWS][COLS] = {0};
int	score = 0;
char GameOn = TRUE;
Shape current;
const Shape ShapesArr[7] =
{
	{(char *[]){(char []){0,1,1},(char []){1,1,0}, (char []){0,0,0}}, 3}, //S_shape
    {(char *[]){(char []){1,1,0},(char []){0,1,1}, (char []){0,0,0}}, 3}, //Z_shape
    {(char *[]){(char []){0,1,0},(char []){1,1,1}, (char []){0,0,0}}, 3}, //T_shape
    {(char *[]){(char []){0,0,1},(char []){1,1,1}, (char []){0,0,0}}, 3}, //L_shape
    {(char *[]){(char []){1,0,0},(char []){1,1,1}, (char []){0,0,0}}, 3}, //ML_shape
    {(char *[]){(char []){1,1},(char []){1,1}}, 2},                       //SQ_shape
};

//functions

Shape CopyShape(Shape shape);
void	Deleteshape(Shape current);
int		CurrentPosition(Shape shape);
void	RandomizeShape();
void	RotateShape(Shape shape);
void	UpdateTable();
void	RemoveRows();
void	Print_grid();
void	MoveCurrentPiece(int key);
int		GameTimeUpadate();

#endif
