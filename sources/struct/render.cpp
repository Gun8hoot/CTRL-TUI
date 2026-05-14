#include "includes/includes.hpp"

void					render_t::setStopThread(bool state)
{
	pthread_mutex_lock(this->mtxStopThread);
	this->stopThread = state;
	pthread_mutex_unlock(this->mtxStopThread);
}

bool					render_t::getStopThread(void)
{
	bool	state;
	pthread_mutex_lock(this->mtxStopThread);
	state = this->stopThread;
	pthread_mutex_unlock(this->mtxStopThread);
	return (state);
}

bool	render_t::calculateWindowSize(struct winsize	&ptrWinSize)
{
		struct winsize	beforeSleep;
		struct winsize	afterSleep;

		while (1)
		{
			if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &beforeSleep) == -1)
				return (false);
			usleep(1000);
			if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &afterSleep) == -1)
				return (false);
			if ((beforeSleep.ws_col == afterSleep.ws_col) && (beforeSleep.ws_row == afterSleep.ws_row))
				break;
		}
		ptrWinSize = afterSleep;
		return (true);
}

render_s::render_s(void)
{
	std::memset(&this->windowDimension, '\0', sizeof(struct winsize));
	mtxStopThread = NULL;
	this->stopThread = false;
	this->renderTid = 0;
}

render_s::~render_s(void)
{
	if (renderTid > 0)
	{
		this->setStopThread(true);
		pthread_join(this->renderTid, NULL);
	}
	if (mtxStopThread != NULL)
	{
		pthread_mutex_destroy(this->mtxStopThread);
		delete this->mtxStopThread;
		this->mtxStopThread = NULL;
	}
	std::cout << "Destructor called" << std::endl;
}
