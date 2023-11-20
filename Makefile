game:
	gcc tetris.c -lncurses -o tetris

del:
	rm tetris

regame: del game
