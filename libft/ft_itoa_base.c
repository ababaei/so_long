/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:49:58 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 17:37:27 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	convert_len(__intmax_t i, int baselen)
{
	int	len;

	len = 0;
	while (i)
	{
		i /= baselen;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(__intmax_t nb, char *base)
{
	__intmax_t	tmp;
	int			len;
	int			baselen;
	char		*ret;

	tmp = ft_abs(nb);
	baselen = ft_strlen(base);
	len = convert_len(nb, baselen);
	if (nb <= 0)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	ret[len] = '\0';
	len--;
	while (len >= 0)
	{
		ret[len] = base[tmp % baselen];
		tmp = tmp / baselen;
		len--;
	}
	if (nb < 0)
		ret[0] = '-';
	return (ret);
}
/*
int main(void)
{
	char *str;

	str = ft_itoa_base(0, "01");
	printf("str = %s\n", str);
}*/
