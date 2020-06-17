/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:03:53 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 11:05:10 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				a;
	unsigned char		*ldst;
	const unsigned char	*lsrc;

	if (!dst && !src)
		return (NULL);
	ldst = (unsigned char*)dst;
	lsrc = (unsigned char*)src;
	a = 0;
	if (lsrc < ldst)
		while (++a <= len)
			ldst[len - a] = lsrc[len - a];
	else
		while (len-- > 0)
			*(ldst++) = *(lsrc++);
	return (dst);
}
