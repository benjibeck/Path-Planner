/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:37:18 by kmaneera          #+#    #+#             */
/*   Updated: 2020/03/07 17:37:19 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//traverse LL to find end have lowest value of bfsindex
//if there is no end, return 0
t_lst    *find_end(t_sto *inf)
{
    t_lst *tmp;
    t_lst *cand;
    int bfsi_tmp;

    cand = 0;
    tmp = *(inf->edges);
    bfsi_tmp = INT_MAX;
    while (tmp)
    {
        if (ft_strcmp(((t_edge*)(tmp->content))->tail, inf->end) == 0)
        {
            if (inf->numofpath_isget == 0)
                inf->numofpath = inf->numofpath + 1;
            if ((((t_edge*)(tmp->content))->bfsindex) < bfsi_tmp)
                {
                    cand = tmp;
                    bfsi_tmp = ((t_edge*)(tmp->content))->bfsindex;
                }
        }
        tmp = tmp->next;
    }
    inf->numofpath_isget = 1;
    // if (cand)
    //     printf("cand } %s:%s > %d\n", ((t_edge*)(cand->content))->head,\
    //                         ((t_edge*)(cand->content))->tail,\
    //                         ((t_edge*)(cand->content))->bfsindex);
    return (cand); //return whatever tmp has, can also be 0, in case there is no <end>
}

void    printpath(t_lst **path)
{
    t_lst *tmp;
    tmp = *path;
    while(tmp)
    {
        if (((t_stone*)tmp->content)->room_name)
            printf("%s<", ((t_stone*)tmp->content)->room_name);
        tmp = tmp->next;
    }
}

//free the current path, which we found out that it's no longer valid
//even though it has end, but can't trace back to the start
t_eachpath *freeunusedpath(t_eachpath *route)
{
    t_lst *tmp1;
    t_lst *tmp2;

    tmp1 = *(route->path);
    while (tmp1)
    {
        tmp2 = tmp1->next;
        free(tmp1->content);
        free(tmp1);
        tmp1 = tmp2;
    }
    free(route->path);
    free(route);
    return NULL;
}

// consider modifying the function below to remove paths that are incomplete
// can this function be written more simply?

//get each path, store it into LL, 
//also delete elems along the way
t_eachpath   *geteachpath(t_sto* inf, t_lst *cand)
{
    t_lst *tmp;
    t_stone *new;
    t_eachpath *route;
    
    // if (((t_edge*)cand->content)->head == 0)
    //     return (0);
    route = (t_eachpath*)ft_memalloc(sizeof(t_eachpath));
    route->path = (t_lst**)ft_memalloc(sizeof(t_lst*));
    route->distance = ((t_edge*)(cand->content))->bfsindex;
    new = (t_stone*)ft_memalloc(sizeof(t_stone));
    new->room_name = ((t_edge*)(cand->content))->tail;
    lst_add(route->path, lstnew(new));
    tmp = cand->next;
    while (tmp) //continue doing so until cand == 0
    {
        if (cand && tmp)
        {
            if ((ft_strcmp(((t_edge*)(cand->content))->head, ((t_edge*)(tmp->content))->tail) == 0)\
            && ((((t_edge*)(cand->content)))->bfsindex == ((t_edge*)(tmp->content))->bfsindex + 1))
            {
                lst_del_join(inf->edges, cand);
                new = (t_stone*)ft_memalloc(sizeof(t_stone));
                new->room_name = ((t_edge*)(tmp->content))->tail;
                lst_add(route->path, lstnew(new));

                cand = tmp;

                if ((ft_strcmp(((t_edge*)tmp->content)->tail, inf->start) == 0) || ft_strcmp(((t_edge*)(tmp->content))->head, inf->start) == 0)
                {
                    new = (t_stone*)ft_memalloc(sizeof(t_stone));
                    new->room_name = inf->start;
                    lst_add(route->path, lstnew(new));
                    lst_del_join(inf->edges, cand);
                    // printpath(route->path);
                    // printf(" | distance = %d\n", route->distance);
                    return (route);
                }
            }
        }
        tmp = tmp->next;
    }
    //it might be impossible for the adapted version to reach this part
    return (freeunusedpath(route));
}