/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:18:49 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/29 19:18:50 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void    readmap_abort(char *line)
{
    free(line);
}

int    is_emptyline(char *line)
{
    //empty line
    if (line[0] == 0)
        return (1);
    return (0);
}

int    read_ant(t_sto *inf, char *line)
{
    //read the number of and in the first line which is not comment
    //based 10 number only
    if (line[0] == '#')
        return (0);

    //if there is no # in a line, but the line isn't in a corrrect format, stop reading
    if (ft_isnumber_base(line, 10) == 0) //the first line, which is not #
        // errexit("The number of ants is invalid!");
        return (1); //BAD
    inf->ant = ft_atoi(line);
    inf->readphase = ROOM; //next, read room positions
    return (0); //GOOD
}

int    read_room(t_sto *inf, char *line)
{
    if (line[0] == '#')
        return (check_se(inf, line));
    return (check_room(inf, line));
}

int    read_links(t_sto *inf, char *line)
{
    if (line[0] == '#') //if its' a comment, ok, next.
        return (0);
    return (check_link(inf, line));
}

void    readmap(t_sto *inf)
{
    char    *line;
    int     gnl_rt;

    line = NULL;
    while ((gnl_rt = get_next_line(STDIN_FILENO, &line)))
    {
        ft_putendl(line);
        if (is_emptyline(line)) //if empty line is spotted, stop reading
            return (readmap_abort(line));
        if (inf->readphase == ANT)
        {
            if (read_ant(inf, line))
                return (readmap_abort(line));
        }
        else if (inf->readphase == ROOM)
        {
            if (read_room(inf, line))
                return (readmap_abort(line));
        }
        else if (inf->readphase == LINKS)
        {
            if (read_links(inf, line))
                return (readmap_abort(line));
        }
        free(line);
    }
}
