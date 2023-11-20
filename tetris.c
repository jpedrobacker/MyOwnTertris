#include "tetris.h"

Shape CopyShape(Shape shape)
{
	Shape new_shape = shape;
	char **copyshape = shape.array;
	new_shape.array = (char**)malloc(new_shape.width * sizeof(char *));
	int i = -1;
	int j;

	while (++i < new_shape.width)
	{
		new_shape.array[i] = (char *)malloc(new_shape.width * sizeof(char));
		j = -1;
		while (++j < new_shape.width)
		{
			new_shape.array[i][j] = copyshape[i][j];
		}
	}
	return (new_shape);
}

void	Deleteshape(Shape current)//Delete current shape
{
	int i = 0;
	while (i < current.width)
	{
		free(current.array[i]);
		i++;
	}
	free(current.array);
}

int		CurrentPosition(Shape shape)
{

}

void	RandomizeShape()//Update current Shape
{
	Shape new_shape = CopyShape(ShapesArr[rand()%7]);
	new_shape.col = rand()%(COLS-new_shape.width+1);
	new_shape.row = 0;
	
	Deleteshape(current);
	current = new_shape;
}

void	RotateShape(Shape shape)
{

}

void	UpdateTable()
{

}

void	RemoveRows()
{

}

void	Print_grid()
{
	char buffer[ROWS][COLS] = {0};
	int i = -1;
	int j;
	while(++i < current.width)
	{
		j = -1;
		while (++j < current.width)
		{
			if (current.array[i][j])
				buffer[current.row+i][current.col+j] = current.array[i][j];
		}
	}
	clear();
	i = -1;
	while (++i < ROWS)
	{
		j = -1;
		while(++j < COLS)
		{
			if (j == 0 || j == COLS)
				printf("|");
			printw("%c ", (Table[i][j] + buffer[i][j])? 'O': ' ');
		}
		printw("\n");
	}
	printw("\nScore: %d\n", score);
}
void	MoveCurrentPiece(int key)
{

}

int		GameTimeUpadate()
{

}
