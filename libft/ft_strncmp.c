/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:42:06 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/04 22:20:31 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	while ((*str1 || *str2) && (count > 0))
	{
		if (*str1 == *str2)
		{
			str2++;
			str1++;
			count--;
		}
		else
			return (*(unsigned char*)str1 - *(unsigned char*)str2);
	}
	return (0);
}
