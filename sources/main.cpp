#include "includes/main.hpp"

volatile sig_atomic_t refreshRender = true;
termManager* termManager::altBuffer = nullptr;

void	resizeWindow(int sig, siginfo_t *ptr1, void *ptr2)
{
	(void)sig;
	(void)ptr1;
	(void)ptr2;
	refreshRender = true;
}

bool	init_resize_sig(struct sigaction &sa)
{
	std::memset(&sa, '\0', sizeof(sa));
	sa.sa_sigaction = resizeWindow;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGWINCH);
	if (sigaction(SIGWINCH, &sa, NULL) == -1)
		return (false);
	return (true);
}

void	loop(t_tui &tui)
{
	unsigned char	buffer[4];

	while (!tui.render.getStopThread())
	{
		if (read(STDIN_FILENO, &buffer, 4) > 0)
		{
			if (buffer[0] == '\x1b')
			{
				switch (buffer[2])
				{
					case 'A': tui.moveMainMenuCursor(-1); break;
					case 'B': tui.moveMainMenuCursor(+1); break;
					case 'C': tui.moveMainMenuCursor(+2); break;
					case 'D': tui.moveMainMenuCursor(-2); break;
				}
			}
			if (buffer[0] == 'q' || buffer[0] == 'Q')
				break;
		}
		fflush(stdin);
		usleep(10000);
	}
}

int main(void)
{
	t_tui	tui;

	if (!init_resize_sig(tui.sa))
		return (1);
	tui.tmanager.enterAltBuffer();
	if (!init_thread(tui))
		return (false);
	loop(tui);
	return (0);
}
