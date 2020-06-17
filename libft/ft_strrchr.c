/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:32:54 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 12:36:24 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *box;

	box = NULL;
	while (*s)
	{
		if (*s == c)
			box = (char*)s;
		s++;
	}
	if (box)
		return (box);
	else
	{
		if (!c)
			return ((char*)s);
		else
			return (NULL);
	}
}
