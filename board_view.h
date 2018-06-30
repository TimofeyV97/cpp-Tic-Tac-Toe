#ifndef BOARD_VIEW
#define BOARD_VIEW
#include "board.h"

class Board_view
{
private:
	Board *board;
	void show();

public:
	Board_view(Board *b);
	void start_game();
};

#endif