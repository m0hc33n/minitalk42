#include "../inc/server.h"

int	get_utf8_bytes_required(char first_byte)
{
	if ((first_byte & 0x80) == 0)
		return (1);
	if ((first_byte & 0xE0) == 0xC0)
		return (2);
	if ((first_byte & 0xF0) == 0xE0)
		return (3);
	if ((first_byte & 0xF8) == 0xF0)
		return (4);
	return (0);
}

void	byte_handle(void)
{
	if (!g_msg.current_byte)
		g_msg.req_bytes = get_utf8_bytes_required(g_msg.current_char);
	g_msg.unicode_seq[g_msg.current_byte] = g_msg.current_char;
	g_msg.current_byte++;
	if (g_msg.req_bytes == g_msg.current_byte)
	{
		write(STDOUT_FILENO, &g_msg.unicode_seq, g_msg.req_bytes);
		g_msg.current_byte = 0;
		ft_memset(&g_msg.unicode_seq, 0, 4);
	}
	g_msg.current_bit = 0;
	g_msg.current_char = 0;
}

static void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_msg.prev_client_pid != (int)info->si_pid)
	{
		ft_memset(&g_msg, 0, sizeof(t_msg));
		g_msg.prev_client_pid = (int)info->si_pid;
	}
	if (signum == SIGUSR1)
		g_msg.current_char = g_msg.current_char << 1;
	else
		g_msg.current_char = (g_msg.current_char << 1) | 1;
	g_msg.current_bit++;
	if (g_msg.current_bit == MAX_BITS)
	{
		if (g_msg.current_char == *(char *)NULL_BYTE)
			kill(info->si_pid, SIGUSR1);
		else
			byte_handle();
	}
	usleep(10);
	kill(info->si_pid, SIGUSR2);
}

static void	init_server(void)
{
	struct sigaction	sa;

	g_msg.current_bit = 0;
	g_msg.current_char = 0;
	g_msg.prev_client_pid = 0;
	g_msg.current_byte = 0;
	write(STDOUT_FILENO, SERVER_BANNER, SERVERBANNERLEN);
	write(STDOUT_FILENO, SERVER_WELCOME, SERVERWELCOMELEN);
	sa.sa_sigaction = sighandler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (-1 == sigaction(SIGUSR1, &sa, NULL))
	{
		write(STDOUT_FILENO, SIGACTIONERR, SIGACTIONERRLEN);
		exit(EXIT_FAILURE);
	}
	if (-1 == sigaction(SIGUSR2, &sa, NULL))
	{
		write(STDOUT_FILENO, SIGACTIONERR, SIGACTIONERRLEN);
		exit(EXIT_FAILURE);
	}
	write(STDOUT_FILENO, STARTLISTENING, STARTLISTENINGLEN);
}

int	main(void)
{
	pid_t	server_pid;

	init_server();
	server_pid = getpid();
	write(STDOUT_FILENO, SERVERPID, SERVERPIDLEN);
	ft_putnbr_fd((int)server_pid, 1);
	write(STDOUT_FILENO, LINE, LINELEN);
	while (1)
	{
		pause();
	}
}
