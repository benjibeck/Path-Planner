/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:25:11 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/05 15:43:41 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	int		index;
	int		len;

	index = 0;
	len = 0;
	if (!(tmp = (char*)s))
		return (NULL);
	while (tmp[index] == ' ' || tmp[index] == '\n' || tmp[index] == '\t')
		index++;
	if (!tmp[index])
		return (ft_strsub(s, index, 1));
	while (tmp[index + len])
		len++;
	while (tmp[index + len] == ' ' || tmp[index + len] == '\n'
			|| tmp[index + len] == '\t' || !tmp[index + len])
		len--;
	return (ft_strsub(s, index, len + 1));
}
