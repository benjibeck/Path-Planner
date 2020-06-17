/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:02:00 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 14:03:04 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	int		n;

	n = 0;
	if (!(s = (char*)malloc(sizeof(char) * (int)size + 1)))
		return (NULL);
	while (n < (int)size)
		s[n++] = '\0';
	s[n] = '\0';
	return (s);
}
