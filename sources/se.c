/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:37:05 by kmaneera          #+#    #+#             */
/*   Updated: 2020/03/05 13:37:06 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//get the name of the start/end rooms and store them in (inf)
//and free prev_line
int    get_se(t_sto *inf) //getstart/end
{
    char    *line;
    char    **line_elems;
    t_room  *room;
    int     i;

    line = NULL;
    if ((get_next_line(STDIN_FILENO, &line) <= 0))
        errexit("Cannot read the file!");
    ft_putendl(line);
    line_elems = ft_strsplit(line, ' ');
    free(line);
    if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
        errexit("Cannot allocate memory!");

    i = 0;
    while (line_elems[i])
    {
        if (i != 0 && ft_isnumber_base(line_elems[i], 10) == 0)
            return (1);
        if (i == 0) //room name
        {
            room->name = strdup(line_elems[i]);
            if (inf->roomtype == START_R)
            {
                inf->start = ft_strdup(line_elems[i]); //dont forget to free this in the end!
                inf->start_isget = 1;
            }
            else if (inf->roomtype == END_R)
            {
                inf->end = ft_strdup(line_elems[i]); //dont forget to free this in the end!
                inf->end_isget = 1;
            }
        }

        else if (i == 1) //pos.x
            room->x = ft_atoi(line_elems[i]);
        else if (i == 2) //pos.y
            room->y = ft_atoi(line_elems[i]);
        free(line_elems[i]);
        i++;
    }
    free(line_elems[i]);
    room->adj = (t_lst**)ft_memalloc(sizeof(t_list*));
    if (i != 3)
        return (1);
    //lst_add_back(inf->map->rooms, lstnew(room));
    lst_add(inf->rooms, lstnew(room));
    free(line_elems);
    return (0);
}

int     check_se(t_sto *inf, char *line) //check for start and end comments
{
    if (ft_strcmp(line, "##start") == 0)
    {
        inf->roomtype = START_R;
        if (inf->start_isget)
            errexit("Error, Start_Room is specified more than once!");
        return (get_se(inf));
    }
    if (ft_strcmp(line, "##end") == 0)
    {
        inf->roomtype = END_R;
        if (inf->end_isget)
            errexit("Error, End_Room is speciied more than once!");
        return (get_se(inf));
    }
    return (0);
}
