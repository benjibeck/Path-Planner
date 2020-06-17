/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:49:37 by kmaneera          #+#    #+#             */
/*   Updated: 2020/03/03 19:49:38 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lst_add_check_abort(t_lst *new)
{
	free(new->content);
	free(new);
}

//for storing adjacencies
//check for repetitive adjacencies
void	lst_add_check(t_lst **alst, t_lst *new)
{
	t_lst *tmp;

	if (!alst || !new)
		return ;
	if (!(*alst))
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
		{
			if (strcmp(new->content, tmp->content) == 0) //check for repetition
				return (lst_add_check_abort(new));
			tmp = tmp->next;
		}
		if (strcmp(new->content, tmp->content) == 0)
			return (lst_add_check_abort(new));
		tmp->next = new;
	}
}

//find and return the pointer to most recently added node in LL
t_lst *just_add_back(t_lst **alst)
{
	t_lst *tmp;

	if (*alst == 0)
		return (0);
	tmp = *(alst);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}