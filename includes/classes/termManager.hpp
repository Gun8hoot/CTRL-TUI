
#pragma once
#include <termios.h>
#include <unistd.h>
#include <csignal>
#include <iostream>
#include "includes/macro.hpp"

class	termManager
{
	private:
		bool		onAltBuffer = false;
		termios		originalTerm;
		static termManager	*altBuffer;
	public:
		termManager(void);
		~termManager(void);

		void	enterAltBuffer(void);
		void	exitAltBuffer(void);
		static void	signalAltBuffer(int sig);
		void	restoreTerminal(void);

		bool getOnAltBuffer(void);
};
