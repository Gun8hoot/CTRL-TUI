#include "includes/main.hpp"

volatile sig_atomic_t hasResizeWindow = true;
termManager* termManager::altBuffer = nullptr;

void	resizeWindow(int sig)
{
	(void)sig;
	hasResizeWindow = true;
}

void	replaceLastLine(std::string str)
{
	std::cout << "\033[2K\r" << std::flush;  // Clear line, move cursor to start
	std::cout << str;
}

void	banner(struct winsize sz)
{
	std::cout << TERM_PURPLE;
	writeToCenterX("  .,~::::::::::::::::::::::::..    :::     \n", sz.ws_col, 2);
	writeToCenterX(",;;;'````';;;;;;;;'''';;;;``;;;;   ;;;     \n", sz.ws_col, 3);
	writeToCenterX("[[[            [[      [[[,/[[['   [[[     \n", sz.ws_col, 4);
	writeToCenterX("$$$            $$      $$$$$$c     $$'     \n", sz.ws_col, 5);
	writeToCenterX("`88bo,__,o,    88,     888b \"88bo,o88oo,.__\n", sz.ws_col, 6);
	writeToCenterX("  \"YUMMMMMP\"   MMM     MMMM   \"W\" \"\"\"\"YUMMM\n", sz.ws_col, 7);
	std::cout << TERM_RESET;
	std::cout.flush();
}

int main(void)
{
	struct winsize	sz;
	termManager		tmanager;

	signal(SIGWINCH, &resizeWindow);			// Handle the window resize signal
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);	// get non-blocking syscall
	tmanager.enterAltBuffer();

	while (true)
	{
		if (hasResizeWindow == true)
		{
			if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &sz) == -1)
				return (1);
			else
			{
				banner(sz);
				box(0, 10, sz.ws_col, sz.ws_col);
				fflush(stdout);
				hasResizeWindow = false;
			}
		}
		sleep(1);
	}
	return (0);
}
