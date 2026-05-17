#include "includes/main.hpp"

void	*render_routine(void	*ptrRender_t)
{
	render_t	*render = (render_t *)ptrRender_t;

	while (!render->getStopThread())
	{
		if (refreshRender == true)
		{
			std::cout << TERM_CLEAR;
			std::cout.flush();
			if (!render->calculateWindowSize(render->windowDimension))
			{
				render->setStopThread(true);
				return (NULL);
			}
			main_menu(render);
			TERM_MOVE_CURSOR(100, 25);
			std::cout << render->cursorPosition;
			refreshRender = false;
		}
		usleep(5000);
	}
	return (ptrRender_t);
}

bool	init_thread(t_tui &tui)
{
	if (tui.render.stopThread == true)
		return (false);
	tui.render.mtxStopThread = new pthread_mutex_t;
	if (tui.render.mtxStopThread == NULL)
		return (false);
	if (pthread_mutex_init(tui.render.mtxStopThread, NULL) != 0)
		return (false);
	if (pthread_create(&tui.render.renderTid, NULL, &render_routine, &tui.render) != 0)
		return (false);
	return (true);
}
