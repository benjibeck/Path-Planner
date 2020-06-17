/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:28:25 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 14:29:36 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *ptr;

	if (!s || !f || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	ptr = str;
	while (*s)
		*(ptr++) = f(*(s++));
	return (str);
}
