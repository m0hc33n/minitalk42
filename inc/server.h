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
# define BUFFER_SIZE 1024

# define SERVER_WELCOME "\n** Welcome to Minitalk Server <3 **\n\n"
# define SERVERWELCOMELEN 38

# define STARTLISTENING "[++] SERVER LISTENING FRO INCOMING SIGNALS\n"
# define STARTLISTENINGLEN 43

# define SERVERPID "[++] SERVER PID : "
# define SERVERPIDLEN 18

typedef struct s_msg
{
	char	current_char;
	int		current_bit;
}			t_msg;

t_msg		g_msg = {0};

#endif
