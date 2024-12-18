#include "../inc/tools.h"

bool	get_pid_from_str(const char *str, int *server_pid)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = (*str - 48) + (res * 10);
		str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str)
		return (false);
	*server_pid = res * sign;
	return (true);
}
