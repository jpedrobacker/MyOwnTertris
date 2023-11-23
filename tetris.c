#include "tetris.h"

Shape NewShape(Shape shape)
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
	char **array = shape.array;
	int i, j;
	i = -1;
	while(++i < shape.width)
	{
		j = -1;
		while (++j < shape.width)
		{
			if (shape.col+j < 0 || shape.col+j >= COLS || shape.row+i >= ROWS)
			{
				if (array[i][j])
					return (FALSE);
			}
			else if (Table[shape.row+i][shape.col+j] && array[i][j])
				return (FALSE);
		}
	}
	return (TRUE);
}

void	RandomizeShape()//Update current Shape
{
	Shape new_shape = NewShape(ShapesArr[rand()%7]);
	new_shape.col = rand()%(COLS-new_shape.width+1);
	new_shape.row = 0;

	Deleteshape(current);
	current = new_shape;
	if(!CurrentPosition(current))// Se a peça chegar no topo, o jogo acaba
		GameOn = FALSE;
}

void	RotateShape(Shape shape)
{

}

void	UpdateTable()
{
	int i, j;
	i = -1;
	while (++i < current.width)
	{
		j = -1;
		while (++j < current.width)
		{
			if(current.array[i][j])
				Table[current.row+i][current.col+j] = current.array[i][j];
		}
	}
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
			printw("%c ", (Table[i][j] + buffer[i][j])? 'O': '.');//Printw usado para printar dinamicamente
		}
		printw("\n");
	}
	printw("\nScore: %d\n", score);
}
void	MoveCurrentPiece(int key)
{
	Shape temp = NewShape(current);
	switch (key)
	{
	case 's':
		temp.row++;
		if(CurrentPosition(temp))
			current.row++;
		else
		{
			UpdateTable();
			RandomizeShape();
		}
		break;
	case 'd':
		temp.col++;
		if (CurrentPosition(temp))
			current.col++;
		break;
	case 'a':
		temp.col--;
		if(CurrentPosition(temp))
			current.col--;
		break;
	case 'w':
		RotateShape(temp);
		if(CurrentPosition(temp))
			RotateShape(current);
		break;
	}
	Deleteshape(temp);
	Print_grid();
}

int		GameTimeUpdate()
{
	return ((suseconds_t)(now.tv_sec*1000000 + now.tv_usec) -((suseconds_t)before_now.tv_sec*1000000 + before_now.tv_usec)) > timer;
}

int main(void)
{
	srand(time(0));
	score = 0;
	int c;
	initscr();
	gettimeofday(&before_now, NULL);
	timeout(1);
	RandomizeShape();
	Print_grid();
	while(GameOn)
	{
		if ((c = getch()) != ERR);
			MoveCurrentPiece(c);
		gettimeofday(&now, NULL);
		if (GameTimeUpdate())
		{
			MoveCurrentPiece('s');
			gettimeofday(&before_now, NULL);
		}
	}
	Deleteshape(current);
	endwin();
	int i;
	int j;
	i = -1;
	while (++i < ROWS)
	{
		j = -1;
		while (++j < COLS){
			printf("%c ", Table[i][j] ? 'O': '.');
		}
		printf("\n");
	}
	printf("\nGame over!\n");
	printf("\nScore: %d\n", score);
	return (0);
}
