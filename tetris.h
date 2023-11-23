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
}Shape;

struct timeval before_now, now;

//Universal variables
char Table[ROWS][COLS] = {0};
int	score = 0;
char GameOn = TRUE;
suseconds_t timer = 400000; // decrease this to make it faster
int decrease = 1000;
Shape current;
Shape hold;

//Shapes
const Shape ShapesArr[7] =
{
	{(char *[]){(char []){0,1,1}, (char []){1,1,0}, (char []){0,0,0}}, 3}, //S
	{(char *[]){(char []){1,1,0}, (char []){0,1,1}, (char []){0,0,0}}, 3}, //Z
	{(char *[]){(char []){0,1,0}, (char []){1,1,1}, (char []){0,0,0}}, 3}, //T
	{(char *[]){(char []){0,0,1}, (char []){1,1,1}, (char []){0,0,0}}, 3}, //L
	{(char *[]){(char []){1,0,0}, (char []){1,1,1}, (char []){0,0,0}}, 3}, //ML
	{(char *[]){(char []){1,1}, (char []){1,1}}, 2}, //SQ_shape
	{(char *[]){(char []){0,0,0,0}, (char []){1,1,1,1}, (char []){0,0,0,0}, (char []){0,0,0,0}}, 4} // |
};

//functions
Shape	NewShape(Shape shape);
void	HoldShape(Shape to_hold);
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
