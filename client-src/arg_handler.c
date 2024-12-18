#include "../inc/client.h"

bool	arg_handler(int ac, char **av, pid_t *server_pid)
{
	if (ac != 3)
		return (false);
	write(STDOUT_FILENO, VERIFYARGS, VERIFYARGSLEN);
	if (!av[1][0] || !av[2][0])
		return (write(STDERR_FILENO, INVALIDARGS, INVALIDARGSLEN), false);
	if (!get_pid_from_str(av[1], server_pid) || *server_pid <= 0)
		return (write(STDOUT_FILENO, INVALID_PID, INVALIDPIDLEN), false);
	return (true);
}
