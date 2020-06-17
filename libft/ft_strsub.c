/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:27:50 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 16:28:46 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;

	if (!s || !(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp = str;
	while (start--)
		s++;
	while (len--)
		*(str++) = *(s++);
	*str = '\0';
	return (tmp);
}
