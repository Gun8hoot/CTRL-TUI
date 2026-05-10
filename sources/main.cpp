#include "includes/main.hpp"

volatile sig_atomic_t hasResizeWindow = false;
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
}

int main(void)
{
	struct winsize	sz;
	termManager		tmanager;
	char c;

	signal(SIGWINCH, &resizeWindow);
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
	tmanager.enterAltBuffer();
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &sz) == -1)
		return (1);
	banner(sz);
	box(1, 1, sz.ws_col - 1, sz.ws_col - 1);
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t┌──────────────────────────┐\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t└──────────────────────────┘\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t╭──────────────────────────╮\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t│                          │\n";
	// std::cout << "\t\t\t\t\t\t\t\t\t\t\t╰──────────────────────────╯\n";

	while (true){
		if (hasResizeWindow == 1)
		{
			if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &sz) == -1)
				return (1);
			banner(sz);
			hasResizeWindow = 0;
		}
		ssize_t n = read(STDIN_FILENO, &c, 1);
		if (n > 0)
		{
			if (c == 'q' || c == 'Q') {
				break;
			}
			std::cout << "You pressed: " << c << "\n";
			std::cout.flush();
		}
		if (n == -1 && errno == EAGAIN)
		{
			usleep(50000);
		}
	}

	tmanager.enterAltBuffer();
	return (0);
}
