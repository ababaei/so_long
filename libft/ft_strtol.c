#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	nbr_base(char c, int base)
{
	if (base <= 10)
		return (c <= '9' && c >= '0');
	return ((c <= '9' && c >= '0') || (c >= 'A' && c <= ('A' + base - 10)) || \
			(c >= 'a' && c <= ('a' + base - 10)));
}

long	fill_nbr(char *nptr, long long nbr, int base)
{
	long	tmp;

	tmp = nbr;
	if (*nptr <= 65 + base && *nptr >= 65)
		tmp = tmp * base + (*nptr - 55);
	else if (*nptr <= 97 + base && *nptr >= 97)
		tmp = tmp * base + (*nptr - 87);
	else if (*nptr <= '9' && *nptr >= '0')
		tmp = tmp * base + (*nptr - 48);
	return (tmp);
}

long	ft_strtol(char *nptr, char **endptr, int base)
{
	long	tmp;
	int		neg;

	neg = 1;
	tmp = 0;
	while (*nptr && (*nptr == ' '
			|| (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (*nptr && nbr_base(*nptr, base - 1))
	{
		tmp = fill_nbr(nptr, tmp, base);
		nptr++;
	}
	*endptr = nptr;
	return (tmp * neg);
}
