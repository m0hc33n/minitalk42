#ifndef TOOLS_H
# define TOOLS_H

# include <stdbool.h>
# include <sys/types.h>
# include <unistd.h>

# define LINE "\n\n\t===================================\n\n"
# define LINELEN 40

# define NULL_BYTE "\0"

// CLIENT
# define VERIFYARGS "[++] VERIFY ARGS ...\n"
# define VERIFYARGSLEN 21

# define VALIDARGS "\t[++] VALID ;)\n"
# define VALIDARGSLEN 15

# define INVALID_PID "\t[--] INVALID SERVER PID\n"
# define INVALIDPIDLEN 25

# define INVALIDARGS "\t[--] INVALID ARGS\n"
# define INVALIDARGSLEN 19

//
int		ft_isspace(int c);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *b, int c, size_t len);

//
bool	get_pid_from_str(const char *str, int *server_pid);
bool	cl_arg_handler(int ac, char **av, pid_t *server_pid);

#endif
