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

int main(void)
{
	t_tui	tui;
	char	buff[8];

	if (!init_resize_sig(tui.sa))
		return (1);
	tui.tmanager.enterAltBuffer();
	if (!init_thread(tui))
		return (false);
	while (!tui.render.getStopThread())
	{
		if (read(STDIN_FILENO, &buff, 8) > 0)
		{
			if (buff[0] == 'q' || buff[0] == 'Q')
				break;
		}
		fflush(stdin);
		usleep(10000);
	}
	return (0);
}
