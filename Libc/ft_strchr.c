/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 07:21:03 by mnarazak          #+#    #+#             */
/*   Updated: 2020/07/21 22:06:10 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (((unsigned char)c) == '\0')
		return ((char *)(s + ft_strlen(s)));
	if (*s == '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == ((unsigned char)c))
			return (char *)(s + i);
		i++;
	}
	return (NULL);
}
