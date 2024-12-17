/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:47:33 by mamazian          #+#    #+#             */
/*   Updated: 2024/12/16 20:47:34 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../inc/tools.h"
# include <signal.h>
# include <stdbool.h>
# include <sys/types.h>
# include <unistd.h>

# define USAGE "USAGAE:\n\t<program> <server pid> <message>\n"
# define USAGELEN 42

# define INVALID_PID "\t[--] INVALID SERVER PID\n"
# define INVALIDPIDLEN 25

# define UNABLESENDMSG "\t[--] UNABLE TO SEND MESSAGE\n"
# define UNABLESENDMSGLEN 29

# define CLIENT_WELCOME "\n** Welcome to Minitalk Client <3 **\n\n"
# define CLIENTWELCOMELEN 38

# define VERIFYARGS "[++] VERIFY ARGS ...\n"
# define VERIFYARGSLEN 21

# define VALIDARGS "\t[++] VALID ;)\n"
# define VALIDARGSLEN 15

# define SENDINGMSG "[++] START SENDING MSG\n"
# define SENDINGMSGLEN 23

# define DONE "[++] DONE !\n"
# define DONELEN 12

#endif
