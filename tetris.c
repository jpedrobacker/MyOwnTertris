#include "tetris.h"

char Table[ROWS][COLS] = {0};
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

void	RandomShape(Shape shape)
{

}

void	print_board()
{
	char buffer[ROWS][COLS] = {0};
	int i = 0;
	int j = 0;

	while(i < current.width)
	{
		while (j < current.width)
		{
			if (current.array[i][j])
				buffer[current.row+i][current.col+j] = current.array[i][j];
			j++;
		}
		i++;
	}
	clear();
	i = 0;
	while (i < COLS-9)
	{
		printw(" ");
		i++;
	}
	i = 0;
	j = 0;
	while (i < ROWS)
	{
		while(j < COLS)
		{
			printw("%c ", (Table[i][j] + buffer[i][j] ? '#': '.'));
			j++;
		}
		printw("\n");
	}
	printw("\nScore: %d\n", score);
	/*while (row <= ROWS)
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
	printw("\nScore: %d\n", score);*/
}

int main(void)
{
	score = 0;
	int c;

	initscr();
	print_board();
	endwin();

	return (0);
}
