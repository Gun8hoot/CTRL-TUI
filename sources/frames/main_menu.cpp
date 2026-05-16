
#include "includes/main.hpp"

void	writeMainMenuText(struct winsize win_size, render_t *render)
{
	int	boxWidth;
	int	boxHeight;

	boxWidth = win_size.ws_col - 2 - 2 - 2;  // - LEFT_SPACE - RIGHT_SPACE - BOX_DRAWING_CHAR
	boxHeight = win_size.ws_row - 9 - 1 - 2; // - TOP_SPACE - BOTTOM_SPACE - BOX_DRAWING_CHAR
	TERM_MOVE_CURSOR(0, 0);
	std::cout << "Height : " << boxHeight << " ; Width : " << boxWidth;
	TERM_MOVE_CURSOR(boxWidth / 2, boxHeight / 2);
	std::cout << "test";
	pthread_mutex_lock(render->mtxCursorPosition);
	TERM_MOVE_CURSOR(10, 10);
	std::cout << render->cursorPosition;
	pthread_mutex_unlock(render->mtxCursorPosition);
	std::cout.flush();
}

void	main_menu(render_t	*render)
{
	box(0, 0, render->windowDimension.ws_col, render->windowDimension.ws_row, TERM_BLUE);
	box(2, 9, render->windowDimension.ws_col - 2, render->windowDimension.ws_row - 1, TERM_GREEN);
	banner(render->windowDimension);
	writeMainMenuText(render->windowDimension, render);
}
