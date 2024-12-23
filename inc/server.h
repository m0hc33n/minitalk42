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
	char	unicode_seq[4];
	int		current_byte;
	int		req_bytes;
	pid_t	prev_client_pid;
}			t_msg;

t_msg		g_msg;

int			get_utf8_bytes_required(int first_byte);

#endif
