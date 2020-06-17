/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:46:35 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/03 12:46:50 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlst_size(t_dlist **alst)
{
	int		elem;
	t_dlist	*tmp;

	elem = 0;
	tmp = *alst;
	while (tmp)
	{
		elem++;
		tmp = tmp->next;
	}
	return (elem);
}
