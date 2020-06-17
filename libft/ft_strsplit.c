/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:29:17 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/05 22:28:22 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_now(const char *s, char c)
{
	int		now;

	now = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			now++;
		while (*s && *s != c)
			s++;
	}
	return (now);
}

static int	get_wl(const char *s, char c)
{
	int		wl;

	wl = 0;
	while (*s && *s != c)
	{
		wl++;
		s++;
	}
	return (wl);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**result;
	int		index[2];

	index[0] = 0;
	if (!s || !c ||
			!(result = (char**)malloc(sizeof(char*) * (get_now(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		index[1] = 0;
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(result[index[0]] = (char*)malloc(sizeof(char) *
				get_wl(s, c) + 1)))
				return (NULL);
			while (*s && *s != c)
				result[index[0]][index[1]++] = (char)*s++;
			result[index[0]][index[1]] = '\0';
			index[0]++;
		}
	}
	result[index[0]] = NULL;
	return (result);
}
