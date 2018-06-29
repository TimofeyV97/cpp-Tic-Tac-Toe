#include "board.h"
#include "board_view.h"



int main()
{
	Board b;
	Board_view v(&b);

	v.start_game();

	return 0;
}