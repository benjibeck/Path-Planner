/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:38:50 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/04 21:55:47 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*ptr[4];

	ptr[2] = (char*)s1;
	if (!*s2)
		return ((char*)s1);
	while (*s1 && (int)(s1 - ptr[2]) < (int)(len))
	{
		ptr[3] = NULL;
		ptr[0] = (char*)s2;
		while (*s1 == *ptr[0]++ && (int)(s1 - ptr[2]) < (int)(len))
		{
			if (!(ptr[3]))
			{
				ptr[1] = (char*)s1;
				ptr[3] = ptr[2];
			}
			if (!(*ptr[0]))
				return (ptr[1]);
			s1++;
		}
		if (ptr[3] == ptr[2] && (int)(s1 - ptr[2]) < (int)(len))
			s1 = ptr[1];
		s1++;
	}
	return (NULL);
}
