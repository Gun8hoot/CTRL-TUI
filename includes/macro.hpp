
#pragma once
#include <iostream>

// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

// Bypass color scheme
# define BY_TERM_RED "\x1b[38;5;9m"
# define BY_TERM_GREEN "\x1b[38;5;10m"
# define BY_TERM_BLUE "\x1b[38;5;20m"
# define BY_TERM_YELLOW "\x1b[38;5;11m"

// Terminal color scheme escape sequence
# define TERM_BLACK "\x1b[0;30m"
# define TERM_RED "\x1b[0;31m"
# define TERM_GREEN "\x1b[0;32m"
# define TERM_YELLOW "\x1b[0;33m"
# define TERM_BLUE "\x1b[0;34m"
# define TERM_PURPLE "\x1b[0;35m"
# define TERM_CYAN "\x1b[0;36m"
# define TERM_WHITE "\x1b[0;37m"

// Terminal background color

// Terminal special escape sequence
# define TERM_RESET "\x1b[0m"
# define TERM_CLEAR "\x1b[2J"
# define TERM_RM_LINE "\x1b[2K"
# define TERM_ENTER_ALT "\x1b[?1049h"
# define TERM_EXIT_ALT "\x1b[?1049l"

// Terminal cursor escape sequence
# define TERM_SHOW_CURSOR "\x1b[?25h"
# define TERM_HIDE_CURSOR "\x1b[?25l"

// Macro
# define TERM_MOVE_CURSOR(X, Y) std::cout << "\x1b[" << Y << ";" << X << "H"
