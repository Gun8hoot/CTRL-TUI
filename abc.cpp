#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <termios.h>
#include <signal.h>
#include "includes/main.hpp"

void	sig(int sig)
{
	(void)sig;
	state = true;
}

int main(int argc, char **argv)
{
	struct termios attr;
    struct termios save;
    struct winsize	sz = {0};

	// signal(SIGWINCH, sig);
	std::cout << TERM_ENTER_ALT;
	std::cout.flush();
    tcgetattr(STDIN_FILENO, &save);
    attr = save;
    attr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &attr);
    uint8_t buf[20];
    ssize_t bytes;
    TERM_MOVE_CURSOR(0, 0);
    while ((bytes = read(STDIN_FILENO, buf, 20)) > 0)
    {
    	if (state == true)
     	{
    		ioctl(STDOUT_FILENO, TIOCGWINSZ, &sz);
    		writeToCenterX("HELLO", sz.ws_col, sz.ws_row);
      		state = false;
      	}
    	if (bytes == 1 && (buf[0] == 'Q' || buf[0] == 'q'))
     		break ;
        for (size_t i = 0; i < bytes; i++) {
            printf("%zd: %hhu\n", i, buf[i]);
        }
    }
    tcgetattr(STDIN_FILENO, &save);
	std::cout << TERM_EXIT_ALT;
	std::cout.flush();
    return 0;
}
