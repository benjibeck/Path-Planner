/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:36:48 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/04 12:30:59 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		flag;
	char	*ptr[2];

	if (!*to_find)
		return ((char*)str);
	while (*str)
	{
		flag = 0;
		ptr[0] = (char*)to_find;
		while (*str == *ptr[0]++)
		{
			if (flag == 0)
			{
				ptr[1] = (char*)str;
				flag = 1;
			}
			if (!(*ptr[0]))
				return (ptr[1]);
			str++;
		}
		if (flag == 1)
			str = ptr[1];
		str++;
	}
	return (NULL);
}
