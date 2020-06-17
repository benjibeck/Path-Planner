/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:40:06 by kmaneera          #+#    #+#             */
/*   Updated: 2020/01/06 10:39:31 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	len = ft_strlen(str);
	tmp = (char*)malloc(sizeof(char) * len + 1);
	ft_strcpy(tmp, str);
	len--;
	tmp2 = str;
	while (len >= 0)
		*(tmp2++) = tmp[len--];
	free(tmp);
	return (str);
}
