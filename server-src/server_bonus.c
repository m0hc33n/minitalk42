/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:28:52 by mamazian          #+#    #+#             */
/*   Updated: 2024/12/17 17:28:53 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

static void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_msg.prev_client_pid != (int)info->si_pid)
	{
		g_msg.prev_client_pid = (int)info->si_pid;
		g_msg.current_bit = 0;
		g_msg.current_char = 0;
	}
	if (signum == SIGUSR1)
		g_msg.current_char = g_msg.current_char << 1;
	else
		g_msg.current_char = (g_msg.current_char << 1) | 1;
	g_msg.current_bit++;
	if (g_msg.current_bit == MAX_BITS)
	{
		write(1, &g_msg.current_char, 1);
		g_msg.current_bit = 0;
		g_msg.current_char = 0;
	}
}

static void	init_server(void)
{
	struct sigaction	sa;

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
