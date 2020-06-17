/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:12:27 by kmaneera          #+#    #+#             */
/*   Updated: 2020/01/16 18:06:20 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int		get_digit(int n)
{
	int		digit;

	if (n == -2147483648)
		return (9);
	if (n < 0)
		n *= -1;
	if (!n)
		return (1);
	else
		digit = 1;
	while ((n /= 10) > 0)
		digit++;
	return (digit);
}

static	char	*ft_itoa_2(char *result, int *helper, int n)
{
	while (helper[0]--)
	{
		helper[3] = n;
		helper[1] = helper[0];
		while (helper[1]--)
			helper[3] = helper[3] / 10;
		result[helper[2]++] = (helper[3] % 10) + '0';
	}
	result[helper[2]] = '\0';
	return (result);
}

char			*ft_itoa(int n)
{
	char	*result;
	int		helper[4];

	helper[2] = 0;
	helper[0] = get_digit(n);
	if (n >= 0)
	{
		if (!(result = (char*)malloc(sizeof(char) * (helper[0] + 1))))
			return (NULL);
	}
	else
	{
		if (!(result = (char*)malloc(sizeof(char) * (helper[0] + 2))))
			return (NULL);
		result[helper[2]++] = '-';
		if (n == -2147483648)
		{
			result[helper[2]++] = '2';
			n = -147483648;
		}
		n = n * -1;
	}
	return (ft_itoa_2(result, helper, n));
}
