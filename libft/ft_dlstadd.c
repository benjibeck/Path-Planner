/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:37:13 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/03 21:37:33 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (alst)
	{
		new->next = *alst;
		new->prev = NULL;
	}
	if (*alst)
	{
		(*alst)->prev = new;
	}
	*alst = new;
}
