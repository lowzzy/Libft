/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:36:00 by mnarazak          #+#    #+#             */
/*   Updated: 2020/07/18 10:32:29 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int num)
{
	int		i;

	if (num == 0)
		return (1);
	i = 0;
	if (num < 0)
	{
		num *= (-1);
		i++;
	}
	while (num >= 1)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char	*ft_main_itoa(int n, char *str, int isminus)
{
	int		tmp;
	int		time;

	time = 0;
	while (n > 0)
	{
		ft_memmove(str + isminus + 1, str + isminus, isminus + time + 1);
		tmp = (n % 10);
		n /= 10;
		str[isminus] = tmp + '0';
		time++;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int			i;
	char		*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(ft_count_digit(n) + 1);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n *= (-1);
	}
	str = ft_main_itoa(n, str, i);
	str[ft_count_digit(n) + 1] = '\0';
	return (str);
}
