/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:38:21 by kmaneera          #+#    #+#             */
/*   Updated: 2020/03/07 10:38:22 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


t_stack *init_stack(void)
{
    t_stack *new;

    new = (t_stack*)ft_memalloc(sizeof(t_stack));
    new->top = 0;
    return (new);
}

void add_stack(t_stack *stack, void *content)
{
    t_lst *new;

    new = (t_lst*)ft_memalloc(sizeof(t_lst));
    new->content = content;
    new->next = stack->top;
    stack->top = new;
}

void *pull_stack(t_stack *stack)
{
    t_lst *tmp;
    void *content;
    //free that node, but not free the information
    if (!stack->top)
        return (0);
    tmp = stack->top;
    content = stack->top->content;
    stack->top = stack->top->next;
    free(tmp);
    return(content);
}

int isempty_stack(t_stack *stack)
{
    if (stack->top == 0)
        return (1);
    return (0);
}