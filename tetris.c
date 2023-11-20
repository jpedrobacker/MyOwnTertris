#include "tetris.h"

int	score = 0;
char GameOn = TRUE;
Shape current;
const Shape ShapesArr[7] =
{
	{(char *[]){(char []){0,1,1},(char []){1,1,0}, (char []){0,0,0}}, 3},      //S_shape
    {(char *[]){(char []){1,1,0},(char []){0,1,1}, (char []){0,0,0}}, 3},      //Z_shape
    {(char *[]){(char []){0,1,0},(char []){1,1,1}, (char []){0,0,0}}, 3},      //T_shape
    {(char *[]){(char []){0,0,1},(char []){1,1,1}, (char []){0,0,0}}, 3},      //L_shape
    {(char *[]){(char []){1,0,0},(char []){1,1,1}, (char []){0,0,0}}, 3},      //ML_shape
    {(char *[]){(char []){1,1},(char []){1,1}}, 2},                            //SQ_shape
};

Shape CopyShape(Shape shape)
{
	Shape new_shape = shape;
	char **copyshape = shape.array;
	new_shape.array = (char**)malloc(new_shape.width * sizeof(char *));
	int i = 0;
	int j = 0;

	while (i < new_shape.width)
	{
		new_shape.array[i] = (char *)malloc(new_shape.width * sizeof(char));
		while (j < new_shape.width)
		{
			new_shape.array[i][j] = copyshape[i][j];
			j++;
		}
		i++;
	}
	return (new_shape);
}

void	deleteshape(Shape shape)
{
	int i = 0;
	while (i < shape.width)
	{
		free(shape.array[i]);
		i++;
	}
	free(shape.array);
}

void	print_board()
{
	int row = 0;
	int col = 0;

	while (row <= ROWS)
	{
		while(col <= COLS)
		{
			if (col == 0 || col == COLS)
				printw("|");
			else if (row == ROWS)
				printw("*");
			else
				printw(" ");
			col++;
		}
		printw("\n");
		row++;
	}
	printw("\nScore: %d\n", score);
}

int main(void)
{
	print_board();
	return (0);
}
