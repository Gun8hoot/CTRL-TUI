#include "includes/main.hpp"

volatile sig_atomic_t hasResizeWindow = false;
termManager* termManager::altBuffer = nullptr;

void	resizeWindow(int sig, siginfo_t *ptr1, void *ptr2)
{
	(void)sig;
	(void)ptr1;
	(void)ptr2;
	hasResizeWindow = true;
}

void	replaceLastLine(std::string str)
{
	std::cout << "\033[2K\r" << std::flush;  // Clear line, move cursor to start
	std::cout << str;
}

bool	init_resize_sig(struct sigaction *sa)
{
	memset(sa, '\0', sizeof(*sa));
	sa->sa_sigaction = resizeWindow;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGWINCH);
	if (sigaction(SIGWINCH, sa, NULL) == -1)
		return (false);
	hasResizeWindow = true;	// First iteration
	return (true);
}

int main(void)
{
	t_tui	tui;
	char	buff[8];

	hasResizeWindow = false;
	std::memset(&tui, '\0', sizeof(t_tui));
	if (!init_resize_sig(&tui.sa))
		return (1);
	tui.tmanager.enterAltBuffer();
	while (true)
	{
		if (hasResizeWindow == true)
		{
			puts(TERM_CLEAR);
			std::cout.flush();
			if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &tui.sz) == -1 && errno != EAGAIN)
				tui.tmanager.restoreTerminal();
			main_menu(tui);
			hasResizeWindow = false;
		}
		if (read(STDIN_FILENO, &buff, 80) > 0)
		{
			if (buff[0] == 'q' || buff[0] == 'Q')
				kill(getpid(), SIGINT);
			writeToCenterX("INPUT CAUGHT", tui.sz.ws_col, tui.sz.ws_row / 2);
			std::cout.flush();
		}
		usleep(100000);
	}
	return (0);
}
