#include "routine.h"

void	exit_routine(void)
{
	// 1. Free all allocated memory
	// 2. Close all file descriptors
	// 3. Exit the program
	exit(1);
}