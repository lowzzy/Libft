/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:34:20 by mnarazak          #+#    #+#             */
/*   Updated: 2020/07/21 17:16:39 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	if (*s1 == '\0' || *s2 == '\0')
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	while (s1[i] && s2[i])
	{
		if (i == n)
		{
			return (((unsigned char *)s1)[i - 1] -
						((unsigned char *)s2)[i - 1]);
		}
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (i == n)
		return (0);
	if (i == ft_strlen(s1) && i == ft_strlen(s2))
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
