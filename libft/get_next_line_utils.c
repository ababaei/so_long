/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:30:37 by ababaei           #+#    #+#             */
/*   Updated: 2021/01/28 13:53:23 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = NULL;
	if (s)
	{
		str = malloc(sizeof(char) * (ft_strlen(s) - start + 2));
		if (str == NULL)
			return (0);
		while (s && start <= ft_strlen(s))
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
		free((char *)s);
		s = NULL;
	}
	return (str);
}

int	isincharset(char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	t_len;
	size_t			i;
	size_t			j;
	char			*ptr;

	j = 0;
	i = 0;
	t_len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (t_len + 1));
	if (ptr == NULL)
		return (0);
	while (s1 && s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	free((char *)s1);
	s1 = NULL;
	return (ptr);
}
