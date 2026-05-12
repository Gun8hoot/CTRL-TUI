#include "includes/main.hpp"

// NOTE FOR LATER : ROW == Y ; COL == X
void	writeToCenterX(const std::string str, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = (x - static_cast<int>(str.length())) / 2 + 1;
	new_y = y;
	if (new_x >= 0 && new_y >= 0)
	{
		TERM_MOVE_CURSOR(0, new_y);
		writeToPos(new_y, new_x, str);
	}
}

void	writeToPos(unsigned int Y, unsigned int X, std::string content)
{
	TERM_MOVE_CURSOR(X, Y);
	std::cout << content;
	std::cout.flush();
}

void	box(int	startX, int startY, int endX, int endY, std::string color)
{
	std::cout.flush() << color;

	for (int y = startY; y < endY; y++)
	{
		for (int x = startX; x < endX; x++)
		{
			TERM_MOVE_CURSOR(startX + x + 1, y + 1);
			if (x == startX && y == startY)
				std::cout << "╭";
			else if (x == endX - 1 && y == startY)
				std::cout << "╮";
			else if (x == startX && y == endY - 1)
				std::cout << "╰";
			else if (x == endX - 1 && y == endY - 1)
				std::cout << "╯";
			else if ((y == startY || y == endY - 1) && (x != startX || x != endX - 1))
				std::cout << "─";
			else if ((x == startX || x == endX - 1) && (y != startY || y != endY))
				std::cout << "│";
			std::cout.flush();
			fflush(stdout);
		}
	}
	std::cout.flush() << TERM_RESET;
}

void	banner(struct winsize sz)
{
	std::cout << TERM_PURPLE;
	writeToCenterX("  .,~::::::::::::::::::::::::..    :::     \n", sz.ws_col, 2);
	writeToCenterX(",;;;'````';;;;;;;;'''';;;;``;;;;   ;;;     \n", sz.ws_col, 3);
	writeToCenterX("[[[            [[      [[[,/[[['   [[[     \n", sz.ws_col, 4);
	writeToCenterX("$$$            $$      $$$$$$c     $$'     \n", sz.ws_col, 5);
	writeToCenterX("`88bo,__,o,    88,     888b \"88bo,o88oo,.__\n", sz.ws_col, 6);
	writeToCenterX("  \"YUMMMMMP\"   MMM     MMMM   \"W\" \"\"\"\"YUMMM\n", sz.ws_col, 7);
	std::cout << TERM_RESET;
	std::cout.flush();
}
