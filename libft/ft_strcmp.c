/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:40:42 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/05 12:24:52 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 || *str2)
	{
		write(1, "hereinstrcmp\n", 12);
		if (*str1 == *str2)
		{
			str2++;
			str1++;
		}
		else
			return (*(unsigned char*)str1 - *(unsigned char*)str2);
	}
	return (0);
}
