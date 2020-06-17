/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:38:41 by kmaneera          #+#    #+#             */
/*   Updated: 2020/01/16 18:05:07 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static char	*ft_itoa_base_unsignedlong_extra(char *res)
{
	res[0] = '0';
	return (res);
}

char		*ft_itoa_base_unsignedlong(unsigned long long int n, int base)
{
	char	*res;
	int		i;

	res = (char*)ft_memalloc(66);
	if (n == 0)
		return (ft_itoa_base_unsignedlong_extra(res));
	i = 0;
	while (n)
	{
		res[i] = n % base;
		if (res[i] >= 0 && res[i] <= 9)
			res[i] = res[i] + '0';
		else
			res[i] = res[i] + 87;
		i++;
		n = n / base;
	}
	return (ft_strrev(res));
}
