#ifndef BOARD_H
#define BOARD_H


enum Winners {X_WIN, O_WIN, DRAW, NO_WIN};
enum Signs {X, O, SPACE};


class Board
{
private:
	int b[10][10];
	static const int FIELD_SIZE;

public:
	Board();
	bool make_move(int x, int y, Signs s);
	int get_size() const;
	Winners is_win();
	int get_cell(int x, int y) const;
};


#endif