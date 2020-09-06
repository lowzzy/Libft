/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 07:22:30 by mnarazak          #+#    #+#             */
/*   Updated: 2020/07/21 22:48:44 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = -1;
	if (((unsigned char)c) == '\0')
		return (char *)(s + ft_strlen(s));
	if (*s == '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == ((unsigned char)c))
		{
			j = i;
		}
		i++;
	}
	return ((j == -1) ? NULL : (char *)(s + j));
}
