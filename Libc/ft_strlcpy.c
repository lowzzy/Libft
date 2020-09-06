/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 07:21:37 by mnarazak          #+#    #+#             */
/*   Updated: 2020/07/16 14:49:15 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	if (dst == NULL || src == NULL)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (len);
	while (i < dstsize - 1)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
		{
			dst[i] = '\0';
			return (len);
		}
		i++;
	}
	dst[i] = '\0';
	return (len);
}
