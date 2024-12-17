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

# define CLIENT_BANNER  "\t========= Minitalk Client =========\n"
# define CLIENTBANNERLEN 37

# define USAGE "USAGAE:\n\t<program> <server pid> <message>\n"
# define USAGELEN 42

# define INVALID_PID "\t[--] INVALID SERVER PID\n"
# define INVALIDPIDLEN 25

# define INVALIDARGS "\t[--] INVALID ARGS\n"
# define INVALIDARGSLEN 19

# define UNABLESENDMSG "\t[--] UNABLE TO SEND MESSAGE (CHECK PID)\n"
# define UNABLESENDMSGLEN 41

# define CLIENT_WELCOME "\n\t** Welcome to Minitalk Client <3 **"
# define CLIENTWELCOMELEN 36

# define VERIFYARGS "[++] VERIFY ARGS ...\n"
# define VERIFYARGSLEN 21

# define VALIDARGS "\t[++] VALID ;)\n"
# define VALIDARGSLEN 15

# define SENDINGMSG "[++] START SENDING MSG\n"
# define SENDINGMSGLEN 23

# define DONE "[++] DONE !\n"
# define DONELEN 12

#endif
