/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:42:06 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/16 21:20:47 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*tmp;
	t_list	*answer;

	ptr = NULL;
	tmp = lst;
	while (tmp)
	{
		if (!ptr)
		{
			ptr = f(tmp);
			answer = ptr;
		}
		else
		{
			ptr->next = f(tmp);
			ptr = ptr->next;
		}
		tmp = tmp->next;
	}
	return (answer);
}
