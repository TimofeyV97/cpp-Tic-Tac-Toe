#include "board.h"

const int Board::FIELD_SIZE = 10;

Board::Board()
{
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
			b[i][j] = SPACE;
	}
}

bool Board::make_move(int x, int y, Signs s)
{
	if (x < 0 || x >= FIELD_SIZE || y < 0 || y >= FIELD_SIZE || b[y][x] != SPACE)
		return false;
	else
	{
		b[y][x] = s;
		return true;
	}
}

int Board::get_size() const
{
	return FIELD_SIZE;
}

Winners Board::is_win()
{
	int cells_x, cells_o;
	int  i, j;
	int check_i, check_j;
	int end_i = (FIELD_SIZE / 2) - 1;
	int end_j = FIELD_SIZE - 1;

	for (i = 0; i < FIELD_SIZE; i++)	// checking rows
	{
		for (j = 0; j < FIELD_SIZE; j++)
		{
			if (b[i][j] == X)
				cells_x++;
			else
				cells_x = 0;

			if (b[i][j] == O)
				cells_o++;
			else
				cells_o = 0;

			if (cells_x == (FIELD_SIZE / 2))
				return X_WIN;
			else if (cells_o == (FIELD_SIZE / 2))
				return O_WIN;
		}

		cells_x = 0;
		cells_o = 0;
	}

	cells_x = 0;
	cells_o = 0;

	for (i = 0; i < FIELD_SIZE; i++)	// checking columns
	{
		for (j = 0; j < FIELD_SIZE; j++)
		{
			if (b[j][i] == X)
				cells_x++;
			else
				cells_x = 0;

			if (b[j][i] == O)
				cells_o++;
			else
				cells_o = 0;

			if (cells_x == (FIELD_SIZE / 2))
				return X_WIN;
			else if(cells_o == (FIELD_SIZE / 2))
				return O_WIN;
		}

		cells_x = 0;
		cells_o = 0;
	}

	check_i = i = FIELD_SIZE / 2;
	j = 0;

	while (check_i >= 0)	// checking left diagonals before main diagonal
	{
		cells_x = 0;
		cells_o = 0;

		while (i < FIELD_SIZE)
		{
			if (b[i][j] == X)
				cells_x++;
			else
				cells_x = 0;

			if (b[i][j] == O)
				cells_o++;
			else
				cells_o = 0;

			if (cells_x == (FIELD_SIZE / 2))
				return X_WIN;
			else if (cells_o == (FIELD_SIZE / 2))
				return O_WIN;

			i++;
			j++;
		}

		check_i--;
		i = check_i;
		j = 0;
	}

	i = 0;
	check_j = j = 1;

	while (check_j != end_j && i != end_i)	// checking remaining left diagonals
	{
		cells_x = 0;
		cells_o = 0;

		while (j < FIELD_SIZE)
		{
			if (b[i][j] == X)
				cells_x++;
			else
				cells_x = 0;

			if (b[i][j] == O)
				cells_o++;
			else
				cells_o = 0;

			if (cells_x == (FIELD_SIZE / 2))
				return X_WIN;
			else if(cells_o == (FIELD_SIZE / 2))
				return O_WIN;

			i++;
			j++;
		}

		i = 0;
		check_j++;
		j = check_j;
	}

	check_i = i = FIELD_SIZE / 2;
	j = end_j;

	while (check_i >= 0)	// checking right diagonals before main diagonal
	{
		cells_x = 0;
		cells_o = 0;

		while (i < FIELD_SIZE)
		{
			if (b[i][j] == X)
				cells_x++;
			else
				cells_x = 0;

			if (b[i][j] == O)
				cells_o++;
			else
				cells_o = 0;

			if (cells_x == (FIELD_SIZE / 2))
				return X_WIN;
			else if(cells_o == (FIELD_SIZE / 2))
				return O_WIN;

			i++;
			j--;
		}

		check_i--;
		i = check_i;
		j = end_j;
	}

	i = 0;
	check_j = j = 8;
	end_i = FIELD_SIZE / 2;
	end_j = 0;

	while (check_j != end_j && i != end_i)	// checking remaining right diagonals
	{
		cells_x = 0;
		cells_o = 0;

		while (j >= 0)
		{
			if (b[i][j] == X)
				cells_x++;
			else
				cells_x = 0;

			if (b[i][j] == O)
				cells_o++;
			else
				cells_o = 0;

			if (cells_x == (FIELD_SIZE / 2))
				return X_WIN;
			else if (cells_o == (FIELD_SIZE / 2))
				return O_WIN;

			i++;
			j--;
		}

		i = 0;
		check_j--;
		j = check_j;
	}

	for (i = 0; i < FIELD_SIZE; i++)	// checking for draw
	{
		for (j = 0; j < FIELD_SIZE; j++)
		{
			if (b[i][j] == SPACE)
				goto no_draw;

		}
	}

	return DRAW;

	no_draw:
	return NO_WIN;
}

int Board::get_cell(int x, int y) const
{
	return b[x][y];
}