/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:37:33 by mnarazak          #+#    #+#             */
/*   Updated: 2020/07/16 15:01:23 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_sufixlen(const char *str, const char *fix)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str) - 1;
	while (i > 0)
	{
		j = 0;
		while (j < ft_strlen(fix))
		{
			if (str[i] == fix[j])
				break ;
			j++;
		}
		if (j == ft_strlen(fix))
			break ;
		i--;
	}
	return (ft_strlen(str) - i - 1);
}

static size_t	ft_prefixlen(const char *str, const char *fix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_strlen(str))
	{
		j = 0;
		while (j < ft_strlen(fix))
		{
			if (str[i] == fix[j])
				break ;
			j++;
		}
		if (j == ft_strlen(fix))
			break ;
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t			prefixlen;
	size_t			sufixlen;
	char			*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	prefixlen = ft_prefixlen(s1, set);
	sufixlen = ft_sufixlen(s1, set);
	if (prefixlen + sufixlen >= ft_strlen(s1))
	{
		str = (char *)malloc(1);
		if (str == NULL)
			return (NULL);
		*str = '\0';
		return (str);
	}
	str = (char *)malloc(ft_strlen(s1) - prefixlen - sufixlen + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1 + prefixlen, ft_strlen(s1) - prefixlen - sufixlen);
	str[ft_strlen(s1) - prefixlen - sufixlen] = '\0';
	return (str);
}
