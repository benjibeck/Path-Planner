/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:39:18 by kmaneera          #+#    #+#             */
/*   Updated: 2020/03/05 13:39:19 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int  free_get_room(char **line_elems, int i)
{
    free(line_elems[i]);
    free(line_elems);
    return (0);
}

int    get_room(t_sto *inf, char **line_elems) //getstart/end
{
    t_room  *room;
    int     i;

    if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
        errexit("Cannot allocate memory!");
    i = 0;
    while (line_elems[i])
    {
        if (i != 0 && ft_isnumber_base(line_elems[i], 10) == 0)
            return (1);
        if (i == 0) //room name
            room->name = strdup(line_elems[i]);
        else if (i == 1) //pos.x
            room->x = ft_atoi(line_elems[i]);
        else if (i == 2) //pos.y
            room->y = ft_atoi(line_elems[i]);
        free(line_elems[i]);
        i++;
    }
    room->adj = (t_lst**)ft_memalloc(sizeof(t_list*));
    if (i != 3)
        return (1);
    lst_add(inf->rooms, lstnew(room));
    return (free_get_room(line_elems, i));
}


int  check_room(t_sto *inf, char *line) 
{
    char    **line_elems;
    int     count;
    if (line[0] == 'L')
        return (1);
    line_elems = ft_strsplit(line, ' ');
    count = 0;
    while (line_elems[count])
        count++;
    //if the number of elems in that line != 3, not a valid line.
    //still need to consider what to do next
    if (count != 3)
    {
        ft_strsplit_free(line_elems);
        return (read_links(inf, line));
    }
    return (get_room(inf, line_elems));
}