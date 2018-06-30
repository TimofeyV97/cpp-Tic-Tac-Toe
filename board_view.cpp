#include <cstdio>
#include "board_view.h"

Board_view::Board_view(Board *b)
{
	board = b;
}

void  Board_view::show()
{
	int size = board->get_size();

	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size; k++)
			printf(" -");

		printf("\n");

		for (int j = 0; j < size; j++)
		{
			printf("|");

			if ((board->get_cell(i, j)) == X)
				printf("X");
			else if ((board->get_cell(i, j)) == O)
				printf("O");
			else
				printf(" ");
		}

		printf("|\n");
	}

	for (int l = 0; l < size; l++)
			printf(" -");

	printf("\n\n");
}

void Board_view::start_game()
{
	Winners winner;
	int x, y;

	printf("Hello! This is Tic-Tac-Toe!\n\n");

	while ((winner = (board->is_win())) == NO_WIN)
	{
		printf("Player 1. Enter coordinates (x, y): ");
		scanf("%d %d", &x, &y);

		while (!(board->make_move(x, y, X)))
		{
			printf("You have entered wrong coordinates! Try again (x, y): ");
			scanf("%d %d", &x, &y);
		}
		
		show();
		winner = board->is_win();

		if (winner != NO_WIN)
			break;

		printf("Player 2. Enter coordinates (x, y): ");
		scanf("%d %d", &x, &y);

		while (!(board->make_move(x, y, O)))
		{
			printf("You have entered wrong coordinates! Try again (x, y): ");
			scanf("%d %d", &x, &y);
		}

		show();
	}

	if (winner == X_WIN)
		printf("X win!\n");
	else if (winner == O_WIN)
		printf("O win!\n");
	else
		printf("Draw!\n");
}