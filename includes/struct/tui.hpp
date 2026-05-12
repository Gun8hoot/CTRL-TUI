
#pragma once
# include "includes/includes.hpp"
# include <sys/ioctl.h>
# include <cstring>

typedef struct	s_tui
{
	s_tui(void)
	{
		std::memset(this, '\0', sizeof(struct s_tui));
	}
	struct sigaction	sa;
	struct	winsize		sz;
	termManager	tmanager;
	int8_t		selection_cursor_pos;
	bool		help_menu;
}	t_tui;
