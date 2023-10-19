#include "routine.h"

// TODO: Change to rl_clear_history from clear_history
void	exit_routine(void)
{
	// 1. Free all allocated memory
	// 2. Close all file descriptors
	// 3. Exit the program
	clear_history();
	exit(1);
}