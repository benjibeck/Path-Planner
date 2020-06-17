/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:28:01 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 23:31:26 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		a;
	char	*res;

	a = 0;
	res = dest;
	if (*src && n > 0)
	{
		while (*dest)
			dest++;
		while (*src && a < (int)n)
		{
			*dest = *src;
			dest++;
			src++;
			a++;
		}
		*dest = '\0';
		return (res);
	}
	else
		return (dest);
}
