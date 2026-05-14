
#pragma once
#include <pthread.h>
#include <vector>
#include <sys/ioctl.h>
#include "includes/enum.hpp"

typedef struct	render_s
{
	render_s(void);
	~render_s(void);
	struct winsize			windowDimension;	// Structure w the dimension of the window
	pthread_mutex_t			*mtxStopThread;		// Mutex of the "stopThread" boolean
	bool					stopThread;			// Boolean that specify if the thread should stop
	pthread_t				renderTid;			// The TIP (Thread IDentifier) of the render thread
	std::vector <void *>	fn_toRender;		// Vector who contain pointer of ever rendering function
	e_main_menu				mainMenuCursor;

	bool					calculateWindowSize(struct winsize	&ptrWinSize);	// Calculate the current size of the window
	void					setStopThread(bool state);
	bool					getStopThread(void);
}				render_t;
