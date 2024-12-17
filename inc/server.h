/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:47:40 by mamazian          #+#    #+#             */
/*   Updated: 2024/12/16 20:47:41 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../inc/tools.h"
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define MAX_BITS 8

# define SERVER_BANNER "\t========= Minitalk Server =========\n"
# define SERVERBANNERLEN 37

# define SERVER_WELCOME "\n\t** Welcome to Minitalk Server <3 **\n\n"
# define SERVERWELCOMELEN 39

# define STARTLISTENING "\tSERVER LISTENING FOR INCOMING MESSAGES\n\n"
# define STARTLISTENINGLEN 41

# define SERVERPID "\tSERVER PID : "
# define SERVERPIDLEN 14

# define SIGACTIONERR "[--] SIGACTION : UNABLE TO REGISTER SIGNAL\n"
# define SIGACTIONERRLEN 43

typedef struct s_msg
{
	char	current_char;
	int		current_bit;
	pid_t	prev_client_pid;
}			t_msg;

t_msg		g_msg = {0};

#endif
