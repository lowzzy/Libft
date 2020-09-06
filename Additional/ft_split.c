/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:36:59 by mnarazak          #+#    #+#             */
/*   Updated: 2020/07/21 20:23:05 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			**ft_free_malloc(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int			ft_element_num(const char *str, char c)
{
	unsigned int	i;
	unsigned int	first_c_index;
	int				element_num;

	if (ft_strchr(str, c))
	{
		element_num = 1;
		first_c_index = ft_strchr(str, c) - str;
		if (first_c_index == ft_strlen(str) - 1)
			return (1);
		else if (first_c_index == 0)
			element_num--;
		i = 0;
		while (str[first_c_index + i + 1])
		{
			if (str[first_c_index + i] == c && str[first_c_index + i + 1] != c)
				element_num++;
			i++;
		}
		return (element_num);
	}
	else
		return (1);
}

static int			ft_element_len(int current, const char *s,
						char c, int current_element_num)
{
	int element_len;

	if ((current_element_num == (ft_element_num(s, c) - 1)) &&
		(s[ft_strlen(s) - 1] != c))
		element_len = ft_strlen(s) - current;
	else
		element_len = ft_strchr(s + current, c) - (s + current);
	return (element_len);
}

static char			**ft_split_main(char **ans, const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < ft_element_num(s, c) && s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if (!(ans[j] = malloc(sizeof(char) *
						(ft_element_len(i, s, c, j) + 1))))
				return (ft_free_malloc(ans));
			ft_memccpy(ans[j], s + i, c, ft_element_len(i, s, c, j));
			ans[j][ft_element_len(i, s, c, j)] = '\0';
			i += ft_element_len(i, s, c, j);
			j++;
		}
	}
	ans[j] = NULL;
	return (ans);
}

char				**ft_split(char const *s, char c)
{
	char **arr;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) == 1) && (*s == c))
		return (NULL);
	if (!(arr = malloc(sizeof(char *) * (ft_element_num(s, c) + 1))))
		return (NULL);
	arr = ft_split_main(arr, s, c);
	return (arr);
}
