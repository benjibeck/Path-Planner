/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:33:32 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 14:35:02 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*ptr;
	int		i;

	i = 0;
	if (!s || !f || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	ptr = str;
	while (s[i])
	{
		*(ptr++) = f(i, s[i]);
		i++;
	}
	return (str);
}
