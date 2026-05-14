
#include "includes/main.hpp"

void	main_menu(render_t	*render)
{
	box(0, 0, render->windowDimension.ws_col, render->windowDimension.ws_row, TERM_BLUE);
	box(1, 9, render->windowDimension.ws_col - 3, render->windowDimension.ws_row - 1, TERM_GREEN);
	banner(render->windowDimension);
}
