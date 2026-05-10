
#include "includes/classes/termManager.hpp"

termManager::termManager(void)
{
	altBuffer = this;
	tcgetattr(STDIN_FILENO, &this->originalTerm);

	signal(SIGINT, this->signalAltBuffer);
	signal(SIGTERM, this->signalAltBuffer);
	signal(SIGQUIT, SIG_IGN);
}

void termManager::enterAltBuffer(void)
{
	termios	raw = originalTerm;

	std::cout << TERM_ENTER_ALT;	// Enter in the alternate screen buffer
	std::cout << TERM_CLEAR;		// Clear screen
	TERM_MOVE_CURSOR(0, 0);			// Move to home (first character/line of the terminal)
	std::cout.flush();
	fflush(stdout);
	this->onAltBuffer = true;

	raw.c_lflag &= ~(ICANON | ECHO);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void	termManager::exitAltBuffer(void)
{
	if (this->onAltBuffer)
	{
		std::cout << TERM_EXIT_ALT;
		std::cout.flush();
		fflush(stdout);
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
