/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:00:39 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 11:02:06 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmpdst;
	const unsigned char	*tmpsrc;

	if (!dst && !src)
		return (NULL);
	tmpdst = (unsigned char*)dst;
	tmpsrc = (unsigned char*)src;
	while (n--)
		*(tmpdst++) = *(tmpsrc++);
	return (dst);
}
