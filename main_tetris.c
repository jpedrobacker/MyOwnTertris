#include "tetris.h"

int main(void)
{
	score = 0;
	int c;

	initscr();
	RandomizeShape();
	Print_grid();
	endwin();

	return (0);
}
