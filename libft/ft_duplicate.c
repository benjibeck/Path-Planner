/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:22:44 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/22 17:46:39 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_duplicate(void const *content, size_t content_size)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	void			*dest;
	int				i;

	i = 0;
	if (!(dest = ft_memalloc(content_size)))
		return (NULL);
	tmp1 = (unsigned char*)content;
	tmp2 = (unsigned char*)dest;
	while (i < (int)content_size)
	{
		*tmp2++ = *tmp1++;
		i++;
	}
	return (dest);
}
