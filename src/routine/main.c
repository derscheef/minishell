#include "routine.h"

// 1. Read input from readline
// 2. Parse input
// 3. Execute command
// 4. Print output

void	routine(void)
{
	// 1. Read input from readline
	while (true)
	{
		char *input = readline("minishell> ");
		if (!input)
			exit_routine();
	}
}