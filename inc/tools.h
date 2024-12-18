#ifndef TOOLS_H
# define TOOLS_H

# include <unistd.h>
# include <stdbool.h>

# define LINE "\n\n\t===================================\n\n"
# define LINELEN 40

//
int			ft_isspace(int c);
int			ft_isdigit(int c);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);

//
bool		get_pid_from_str(const char *str, int *server_pid);

#endif
