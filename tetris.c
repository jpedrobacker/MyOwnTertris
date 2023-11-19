#include "tetris.h"

int scoreInc = 5;
int	myscore = 0;

void	create_board()
{
	for(int row = 0; row <= ROWS; ++row)
	{
		for(int col = 0; col <= COLS; ++col)
		{
			if (col == 0 || col == COLS)
				printf("|");
			else if (row == ROWS)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

int main(void)
{
	create_board();
	return (0);
}
