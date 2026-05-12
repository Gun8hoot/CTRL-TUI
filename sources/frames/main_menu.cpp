
#include "includes/main.hpp"

void	main_menu(t_tui	&tui)
{
	box(0, 0, tui.sz.ws_col, tui.sz.ws_row, TERM_BLUE);
	box(1, 9, tui.sz.ws_col - 3, tui.sz.ws_row - 1, TERM_GREEN);
	// if (tui.help_menu == false)
	// {
	// 	box(2, 10, tui.sz.ws_col - 6, tui.sz.ws_row - 2, TERM_RED);
	// }
	banner(tui.sz);
}
