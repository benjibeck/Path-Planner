/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:27:17 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/16 21:22:48 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content)
{
	t_dlist *list;

	if (!(list = (t_dlist*)ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	if (!content)
		list->content = NULL;
	else
	{
		// if ((list->content = ft_duplicate(content, sizeof(int))) == NULL)
		// 	return (NULL);
		list->content = (void*)content;
	}
	list->prev = NULL;
	list->next = NULL;
	return (list);
}
