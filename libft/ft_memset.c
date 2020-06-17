/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:58:07 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 10:59:22 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t len)
{
	unsigned char *tmp;

	tmp = (unsigned char*)ptr;
	while (len--)
		*(tmp++) = (unsigned char)x;
	return (ptr);
}
