#include "../inc/tools.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	if (fd < 0)
		return ;
	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd(45, fd);
		nbr = -nbr;
	}
	if (nbr <= 9)
	{
		ft_putchar_fd(nbr + 48, fd);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + 48, fd);
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
	{
		*(unsigned char *)(b + len) = (unsigned char)c;
	}
	return (b);
}
