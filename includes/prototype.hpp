
#pragma once
# include "includes/includes.hpp"

void	writeToPos(unsigned int Y, unsigned int X, std::string content);
void	writeToCenterX(const std::string str, int col, int row);
void	box(int	startX, int startY, int endX, int endY, std::string color);
void	banner(struct winsize sz);
void	main_menu(t_tui	&tui);
