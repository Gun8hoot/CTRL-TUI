
#include "includes/main.hpp"

void	writeMainMenuText(struct winsize win_size, std::string text, std::string color)
{
	int	boxWidth;
	int	boxHeight;

	(void)color;
	(void)text;

	boxWidth = win_size.ws_col - 2 - 2 - 2;
	boxHeight = win_size.ws_row - 9 - 1 - 2;
	TERM_MOVE_CURSOR(0, 0);
	std::cout << "Height : " << boxHeight << " ; Width : " << boxWidth;
	std::cout.flush();
}

void	main_menu(render_t	*render)
{
	box(0, 0, render->windowDimension.ws_col, render->windowDimension.ws_row, TERM_BLUE);
	box(2, 9, render->windowDimension.ws_col - 2, render->windowDimension.ws_row - 1, TERM_GREEN);
	banner(render->windowDimension);
	writeMainMenuText(render->windowDimension, "", "");
	// writeToPos((render->windowDimension.ws_row / 2) - 9, 0, "hello");
}
