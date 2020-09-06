/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:37:44 by mnarazak          #+#    #+#             */
/*   Updated: 2020/07/21 17:23:50 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_substr_len(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i + start] && i < len)
		i++;
	return (i);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start || len == 0)
	{
		sub = (char *)malloc(1);
		if (sub == NULL)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	sub = (char *)malloc(ft_substr_len(s, start, len) + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
