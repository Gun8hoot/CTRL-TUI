
#include "includes/classes/termManager.hpp"

termManager::termManager(void)
{
	altBuffer = this;
	tcgetattr(STDIN_FILENO, &this->originalTerm);

	signal(SIGINT, this->signalAltBuffer);
	signal(SIGTERM, this->signalAltBuffer);
	signal(SIGQUIT, SIG_IGN);
}

void	termManager::enterRawMode(void)
{
	std::cout << TERM_ENTER_ALT;
	std::cout.flush();
	std::cout << TERM_CLEAR << TERM_HIDE_CURSOR;
	std::cout.flush();
}

void termManager::enterAltBuffer(void)
{
	termios	raw = originalTerm;

	raw.c_lflag &= ~(ICANON | ECHO);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &raw);

	std::cout << TERM_ENTER_ALT;	// Enter in the alternate screen buffer
	std::cout.flush();
	std::cout << TERM_CLEAR << TERM_HIDE_CURSOR;
	std::cout.flush();
	this->onAltBuffer = true;
}


void termManager::exitAltBuffer(void)
{
	if (this->onAltBuffer)
	{
		// std::cout << "\033[?1000h";		// Re-enable mouse button clicks
		// std::cout << "\033[?1002h";		// Re-enable mouse drag
		// std::cout << "\033[?1003h";		// Re-enable mouse motion
		std::cout << TERM_EXIT_ALT << TERM_SHOW_CURSOR;
		std::cout.flush();
		this->onAltBuffer = false;
	}
}



void	termManager::restoreTerminal(void)
{
	exitAltBuffer();
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &this->originalTerm);
}

termManager::~termManager(void)
{
	this->restoreTerminal();
}

void termManager::signalAltBuffer(int sig)
{
	(void)sig;
	if (altBuffer)
	{
		altBuffer->restoreTerminal();
	}
	exit(0);
}
