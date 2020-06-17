/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:54:12 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/17 10:55:21 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*b;
	char		*e;
	const char	*s;

	b = dest;
	e = dest + size;
	s = src;
	while ((*s) && (b < e))
		*(b++) = *(s++);
	if (b < e)
		*b = 0;
	else if (size > 0)
		b[-1] = 0;
	while (*s != '\0')
		s++;
	return (s - src);
}
