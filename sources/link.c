/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:37:10 by kmaneera          #+#    #+#             */
/*   Updated: 2020/03/05 13:37:11 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


int     can_add(t_sto *inf, char *cand)
{
    t_lst *tmp;

    tmp = (*(inf->rooms));
    while (tmp)
    {
        if (ft_strcmp(cand, ((t_room*)(tmp->content))->name) == 0)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}
//store  adjacencies into linked list of each room
//must display error if the room name mentioned isn't valid
int     get_link(t_sto *inf, char **line_elems)
{
    t_lst *tmp;
    int finding;

    tmp = (*(inf->rooms));
    finding = 0;
    while (tmp)//check if the 2 names are the name of valid room
    {
        if (ft_strcmp(line_elems[0], ((t_room*)(tmp->content))->name) == 0\
        && (can_add(inf, line_elems[1])))
        {
            lst_add_check(((t_room*)tmp->content)->adj, lstnew(ft_strdup(line_elems[1])));
            finding++;
        }
        else if (ft_strcmp(line_elems[1], ((t_room*)(tmp->content))->name) == 0\
        && (can_add(inf, line_elems[0])))
        {
            lst_add_check(((t_room*)tmp->content)->adj, lstnew(ft_strdup(line_elems[0])));
            finding++;
        }
        if (finding == 2)
            break;
        tmp = tmp->next;
    }
    if (finding != 2 && ft_strcmp(line_elems[0], line_elems[1]))//if the process reach this line but finding != 2 > error!, invalid map input
    {
        ft_strsplit_free(line_elems);
        return (1);
    }
    ft_strsplit_free(line_elems);
    return (0);
}

//a function check if a certain line is a line containing information about links or not
//if yes, call get_link
//to be a valid information about link
//both must be the name of valid room
//seperated by "-"
//have only 2 elems
int     check_link(t_sto *inf, char *line)
{
    char **line_elems;
    int i;

    if (!(ft_strchr(line, '-')))
        return (1); //if there is no '-' in that line, error!
    //check for - , and 2 elems
    line_elems = ft_strsplit(line, '-');
    i = 0;
    while (line_elems[i])
        i++;
    if (i != 2) //if the number elems in the line isn't 2, ignore that line
        return (1);
    // inf->room_isget = 1; //based on the assumption that all the room pos.
    //                     //must be read already
    if (inf->readphase == ROOM)
        inf->readphase = LINKS;                    
    return (get_link(inf, line_elems));
}
