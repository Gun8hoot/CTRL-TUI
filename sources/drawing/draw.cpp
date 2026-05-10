#include "includes/main.hpp"

// NOTE FOR LATER : ROW == Y ; COL == X
void	writeToCenterX(const std::string str, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = (x - static_cast<int>(str.length())) / 2 + 1;
	new_y = y;
	if (new_x >= 0 && new_y >= 0)
		writeToPos(new_y, new_x, str);
}

void	writeToPos(unsigned int Y, unsigned int X, std::string content)
{
	TERM_MOVE_CURSOR(X, Y);
	std::cout << content;
	std::cout.flush();
}
