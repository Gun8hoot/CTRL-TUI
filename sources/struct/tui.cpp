
#include "includes/struct/tui.hpp"

void	t_tui::moveMainMenuCursor(int newPos)
{
	int updatedPos;

	pthread_mutex_lock(this->render.mtxCursorPosition);
	updatedPos = this->render.cursorPosition + newPos;
	if (updatedPos >= 0 && updatedPos < 4)
		this->render.cursorPosition = updatedPos;
	pthread_mutex_unlock(this->render.mtxCursorPosition);
}
