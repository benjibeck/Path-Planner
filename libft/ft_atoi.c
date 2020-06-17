/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:46:56 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/03 12:48:01 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int			neg;
	long long	result;

	result = 0;
	neg = 1;
	while (*str == ' ' || *str == '\v' || *str == '\n' || *str == '\t'
			|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		neg = neg * -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if (result > 9223372036854775807)
		return (neg < 0 ? 0 : -1);
	return (result * neg);
}
