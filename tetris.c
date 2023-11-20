#include "tetris.h"

int	score = 0;
char GameOn = TRUE;
const Shape ShapesArr[7] =
{
	{(char *[]){(char []){0,1,1},(char []){1,1,0}, (char []){0,0,0}}, 3},      //S_shape
    {(char *[]){(char []){1,1,0},(char []){0,1,1}, (char []){0,0,0}}, 3},      //Z_shape
    {(char *[]){(char []){0,1,0},(char []){1,1,1}, (char []){0,0,0}}, 3},      //T_shape
    {(char *[]){(char []){0,0,1},(char []){1,1,1}, (char []){0,0,0}}, 3},      //L_shape
    {(char *[]){(char []){1,0,0},(char []){1,1,1}, (char []){0,0,0}}, 3},      //ML_shape
    {(char *[]){(char []){1,1},(char []){1,1}}, 2},                            //SQ_shape
};

void	print_board()
{
	for(int row = 0; row <= ROWS; ++row)
	{
		for(int col = 0; col <= COLS; ++col)
		{
			if (col == 0 || col == COLS)
				printw("|");
			else if (row == ROWS)
				printw("*");
			else
				printw(" ");
		}
		printw("\n");
	}
	printw("\nScore: %d\n", score);
}

int main(void)
{
	print_board();
	return (0);
}
