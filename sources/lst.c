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

void	lst_add_back(t_lst **alst, t_lst *new)
{
	t_lst *tmp;

	if (!alst || !new)
	{
		return ;
	}
	if (!(*alst))
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	lst_del_join_spe(t_lst **alst, t_lst *new)
{
	t_lst *tmp;
	t_lst *tmp2;
	tmp = *alst;
	//the case that <new> node is at the beginning of the list
	if (new == (*alst))
	{
		*alst = (*alst)->next;
		// free(new->content);
		free(new);
		return ;
	}
	while (tmp->next != new)
		tmp = tmp->next;
	tmp2 = new->next;
	tmp->next = tmp2;
	free(new->content);//
	free(new);
}

void	lst_del_join(t_lst **alst, t_lst *new)
{
	t_lst *tmp;
	t_lst *tmp2;
	tmp = *alst;
	//the case that <new> node is at the beginning of the list
	if (new == (*alst))
	{
		*alst = (*alst)->next;
		free(new->content);
		free(new);
		return ;
	}
	while (tmp->next != new)
		tmp = tmp->next;
	tmp2 = new->next;
	tmp->next = tmp2;
	free(new->content);//
	free(new);
}

void	lst_add(t_lst **alst, t_lst *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}


//the memory of the content must be already allocated!
//t_lst	*lstnew(void const *content)
t_lst	*lstnew(void *content)
{
	t_lst *list;

	if (!(list = (t_lst*)ft_memalloc(sizeof(t_lst))))
		return (NULL);

	if (!content)
		list->content = NULL;
	else
        list->content = content;
	list->next = NULL;
	return (list);
}
