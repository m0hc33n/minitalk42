#include "../inc/client.h"

static void	print_banner(void)
{
	write(STDOUT_FILENO, CLIENT_BANNER, CLIENTBANNERLEN);
	write(STDOUT_FILENO, CLIENT_WELCOME, CLIENTWELCOMELEN);
	write(STDERR_FILENO, LINE, LINELEN);
}

static bool	send_bits(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (!(c >> i & 1))
		{
			if (kill(server_pid, SIGUSR1) == -1)
				return (false);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				return (false);
		}
		i--;
		usleep(600);
	}
	return (true);
}

static bool	send_msg(pid_t server_pid, char *msg)
{
	char	c;

	while (*msg)
	{
		c = *msg;
		if (!send_bits(server_pid, c))
			return (false);
		msg++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	print_banner();
	if (!arg_handler(ac, av, &server_pid))
	{
		write(STDOUT_FILENO, USAGE, USAGELEN);
		return (-1);
	}
	write(STDOUT_FILENO, VALIDARGS, VALIDARGSLEN);
	write(STDOUT_FILENO, SENDINGMSG, SENDINGMSGLEN);
	if (!send_msg(server_pid, av[2]))
	{
		write(STDOUT_FILENO, UNABLESENDMSG, UNABLESENDMSGLEN);
		return (-2);
	}
	write(STDOUT_FILENO, DONE, DONELEN);
	return (0);
}
