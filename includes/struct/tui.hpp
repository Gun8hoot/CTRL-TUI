
#pragma once
# include <sys/ioctl.h>
# include <csignal>
# include "includes/classes/termManager.hpp"
# include "includes/struct/render.hpp"

typedef struct	s_tui
{
	struct sigaction	sa = {};
	struct	winsize		sz  = {};
	termManager			tmanager;
	render_t			render;
	bool				help_menu = false;
	bool				criticalError = false;

	void				moveMainMenuCursor(int newPos);
}	t_tui;
