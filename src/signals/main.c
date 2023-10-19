#include "signal.h"

void	handle_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGTERM, sigterm_handler);
	signall(SIGKILL, sigkill_handler);
	signal(SIGSEV, sigsev_handler);
}

void	sigint_handler(int signum)
{
	(void)signum;
	printf("SIGINT\n");
}

void	sigterm_handler(int signum)
{
	(void)signum;
	printf("SIGTERM\n");
}

void	sigkill_handler(int signum)
{
	(void)signum;
	printf("SIGKILL\n");
}

void	sigsev_handler(int signum)
{
	(void)signum;
	printf("SIGSEV\n");
}