#ifndef CLIENT_H
# define CLIENT_H

# include "../inc/tools.h"
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define CLIENT_BANNER "\t========= Minitalk Client =========\n"
# define CLIENTBANNERLEN 37

# define USAGE "USAGAE:\n\t<program> <server pid> <message>\n"
# define USAGELEN 42

# define UNABLESENDMSG "\t[--] UNABLE TO SEND MESSAGE (CHECK PID)\n"
# define UNABLESENDMSGLEN 41

# define CLIENT_WELCOME "\n\t** Welcome to Minitalk Client <3 **"
# define CLIENTWELCOMELEN 36

# define SENDINGMSG "[++] START SENDING MSG\n"
# define SENDINGMSGLEN 23

# define SIGACTIONERR "[--] SIGACTION : UNABLE TO REGISTER SIGNAL\n"
# define SIGACTIONERRLEN 43

# define SERVER_ACK "[++] SERVER ACK (MSG RECEIVED)\n"
# define SERVERACKLEN 31

# define DONE "[++] DONE !\n"
# define DONELEN 12

typedef struct s_info
{
	bool	ack;
	pid_t	server_pid;
}			t_info;

t_info		g_info;

#endif
