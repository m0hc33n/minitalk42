#include "../inc/client.h"

static void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		write(STDOUT_FILENO, SERVER_ACK, SERVERACKLEN);
}

static void	init_client(void)
{
	write(STDOUT_FILENO, CLIENT_BANNER, CLIENTBANNERLEN);
	write(STDOUT_FILENO, CLIENT_WELCOME, CLIENTWELCOMELEN);
	write(STDERR_FILENO, LINE, LINELEN);
	signal(SIGUSR1, sighandler);
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
	send_bits(server_pid, *(char *)NULL_BYTE);
	return (true);
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	init_client();
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
