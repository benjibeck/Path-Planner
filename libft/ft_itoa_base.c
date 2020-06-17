/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:38:41 by kmaneera          #+#    #+#             */
/*   Updated: 2020/01/16 18:07:12 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static char	*ft_itoa_base_extra(char *res, long long int n)
{
	if (n == LONG_MIN)
		return (ft_strcpy(res, "-9223372036854775808"));
	res[0] = '0';
	return (res);
}

char		*ft_itoa_base(long long int n, int base)
{
	char	*res;
	int		neg;
	int		i;

	res = (char*)ft_memalloc(66);
	if (n == 0 || n == LONG_MIN)
		return (ft_itoa_base_extra(res, n));
	neg = 1;
	if (n < 0)
		neg = -1;
	n *= neg;
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
	if (neg == -1)
		res[i] = '-';
	return (ft_strrev(res));
}
