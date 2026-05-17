
#include "includes/main.hpp"

void	mainMenuText(int greenBoxWidth, int greenBoxHeight, std::string str, int cursorPos, int currentCursorPos)
{
	(void)greenBoxHeight;
	(void)greenBoxWidth;
	(void)cursorPos;
	TERM_MOVE_CURSOR(greenBoxWidth - (str.length() / 2), greenBoxHeight);
	if (currentCursorPos == cursorPos)
		std::cout << TERM_GREEN + str + TERM_RESET;
	else
		std::cout << str;
}

void	writeMainMenuText(struct winsize win_size, render_t *render)
{
	int	greenBoxWidth;
	int	greenBoxHeight;
	int greenBoxCenterWidth;
	int greenBoxCenterHeight;

	(void)render;
	greenBoxWidth = win_size.ws_col - 2 - 2 - 2;  // - LEFT_SPACE - RIGHT_SPACE - BOX_DRAWING_CHAR
	greenBoxHeight = win_size.ws_row - 9 - 1 - 2; // - TOP_SPACE - BOTTOM_SPACE - BOX_DRAWING_CHAR
	greenBoxCenterWidth = 2 + 2 + greenBoxWidth / 2;
	greenBoxCenterHeight = 9 + 2 + greenBoxHeight / 2;
	TERM_MOVE_CURSOR(0, 0);
	std::cout << "Height : " << greenBoxHeight << " ; Width : " << greenBoxWidth;
	mainMenuText(greenBoxCenterWidth, greenBoxCenterHeight - 4, MAIN_MENU_1ST, render->cursorPosition, 0);
	mainMenuText(greenBoxCenterWidth, greenBoxCenterHeight - 2, MAIN_MENU_2ST, render->cursorPosition, 1);
	mainMenuText(greenBoxCenterWidth, greenBoxCenterHeight + 0, MAIN_MENU_3ST, render->cursorPosition, 2);
	mainMenuText(greenBoxCenterWidth, greenBoxCenterHeight + 2, MAIN_MENU_4ST, render->cursorPosition, 3);
	mainMenuText(greenBoxCenterWidth, greenBoxCenterHeight + 4, MAIN_MENU_5ST, render->cursorPosition, 4);
}

void	main_menu(render_t	*render)
{
	box(0, 0, render->windowDimension.ws_col, render->windowDimension.ws_row, TERM_BLUE);
	box(2, 9, render->windowDimension.ws_col - 2, render->windowDimension.ws_row - 1, TERM_GREEN);
	banner(render->windowDimension);
	writeMainMenuText(render->windowDimension, render);
	std::cout.flush();
}
