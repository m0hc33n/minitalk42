#include "../inc/client.h"

static void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_info.server_pid == (int)info->si_pid && signum == SIGUSR1)
	{
		g_info.ack = 1;
	}
}

static void	init_client(void)
{
	struct sigaction	sa;

	g_info.ack = 0;
	write(STDOUT_FILENO, CLIENT_BANNER, CLIENTBANNERLEN);
	write(STDOUT_FILENO, CLIENT_WELCOME, CLIENTWELCOMELEN);
	write(STDERR_FILENO, LINE, LINELEN);
	sa.sa_sigaction = sighandler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (-1 == sigaction(SIGUSR1, &sa, NULL))
	{
		write(STDOUT_FILENO, SIGACTIONERR, SIGACTIONERRLEN);
		exit(EXIT_FAILURE);
	}
}

static bool	send_bits(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_info.ack = 0;
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
		while (!g_info.ack)
			pause();
		i--;
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
	if (!cl_arg_handler(ac, av, &g_info.server_pid))
	{
		write(STDOUT_FILENO, USAGE, USAGELEN);
		return (-1);
	}
	init_client();
	write(STDOUT_FILENO, VALIDARGS, VALIDARGSLEN);
	write(STDOUT_FILENO, SENDINGMSG, SENDINGMSGLEN);
	if (!send_msg(g_info.server_pid, av[2]))
	{
		write(STDOUT_FILENO, UNABLESENDMSG, UNABLESENDMSGLEN);
		return (-2);
	}
	write(STDOUT_FILENO, DONE, DONELEN);
	return (0);
}
