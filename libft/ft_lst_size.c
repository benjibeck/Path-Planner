/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:54:55 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/17 09:55:54 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size(t_list **alst)
{
	int		elem;
	t_list	*tmp;

	elem = 0;
	tmp = *alst;
	while (tmp)
	{
		elem++;
		tmp = tmp->next;
	}
	return (elem);
}
