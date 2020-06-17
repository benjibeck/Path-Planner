/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:29:38 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 12:31:21 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int	a;
	int	ldest;
	int	lsrc;

	a = 0;
	ldest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	if ((int)size > (ldest + 1))
	{
		while (*dest)
			dest++;
		while ((*src) && ((int)size > (ldest + a++ + 1)))
			*(dest++) = *(src++);
		*dest = '\0';
	}
	if ((ldest + lsrc) > (lsrc + (int)size))
		return (lsrc + (int)size);
	else
		return (ldest + lsrc);
}
