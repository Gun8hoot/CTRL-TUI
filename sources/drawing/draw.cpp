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
		std::cout << TERM_RM_LINE;
		std::cout.flush();
		writeToPos(new_y, new_x, str);
	}
}

void	writeToPos(unsigned int Y, unsigned int X, std::string content)
{
	TERM_MOVE_CURSOR(X, Y);
	std::cout << content;
	std::cout.flush();
}

void	box(int	startX, int startY, int endX, int endY)
{
	std::cout << TERM_BLUE;
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
			else
				std::cout << " ";
			std::cout.flush();
			fflush(stdout);

		}
	}
	std::cout << TERM_RESET;
}
