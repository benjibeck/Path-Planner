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


t_queue *init_q(void)
{
    t_queue *new;

    new = (t_queue*)ft_memalloc(sizeof(t_queue));
    new->first = 0;
    new->last = 0;
    return (new);
}

void add_q(t_queue *queue, void *content)
{
    t_lst *new;

    new = (t_lst*)ft_memalloc(sizeof(t_lst));
    new->content = content;
    new->next = 0;
    if (!queue->first)
        queue->first = new;
    if (queue->last)
        queue->last->next = new;
    queue->last = new;
}

void *pull_q(t_queue *queue)
{
    t_lst *tmp;
    void *content;
    //free that node, but not free the information
    if (!queue->first)
        return (0);
    tmp = queue->first;
    content = tmp->content;
    queue->first = queue->first->next;
    if (queue->first == 0)
        queue->last = 0;
    free(tmp);
    return(content);
}

void *peek_q(t_queue *queue)
{
    if (queue->first == 0)
        return (0);
    return (queue->first->content);
}

int isempty_q(t_queue *queue)
{
    if (queue->first == 0)
        return (1);
    return (0);
}