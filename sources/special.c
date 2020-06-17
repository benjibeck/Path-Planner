#include "lem_in.h"

void    rm_sfn(t_sto *inf)
{
    t_lst *tmp;
    t_lst *tmp2;

    tmp = *(inf->rooms);
    while (tmp)
    {
        if (ft_strcmp(((t_room*)tmp->content)->name, inf->end) == 0)
        {
            tmp2 = (*(((t_room*)(tmp->content))->adj));
            while (tmp2)
            {
                if (ft_strcmp(((char*)tmp2->content), inf->start) == 0) //YES
                {
                    free(tmp2->content);
                    return (lst_del_join_spe(((t_room*)(tmp->content))->adj, tmp2));
                }
                tmp2 = tmp2->next;
            }
            break;
        }
        tmp = tmp->next;
    }
}


//if end adj to start, rm the link and return 1 
int     isendadj(t_sto *inf)
{
   t_lst *tmp;
   t_lst *tmp2;

    tmp = *(inf->rooms);
    while (tmp)
    {
        if (ft_strcmp(((t_room*)tmp->content)->name, inf->start) == 0)
        {
            tmp2 = (*(((t_room*)(tmp->content))->adj));
            while (tmp2)
            {
                if (ft_strcmp((char*)tmp2->content, inf->end) == 0) //YES
                {
                    free(tmp2->content);
                    lst_del_join_spe(((t_room*)(tmp->content))->adj, tmp2);
                    rm_sfn(inf);
                    return (1);
                }
                tmp2 = tmp2->next;
            }
            break;
        }
        tmp = tmp->next;
    }
    return (0);
}

//
void    addsepath(t_sto *inf)
{
    t_stone *new;
    t_eachpath *route;

    route = (t_eachpath*)ft_memalloc(sizeof(t_eachpath));
    route->path = (t_lst**)ft_memalloc(sizeof(t_lst*));
    route->distance = 2;
    new = (t_stone*)ft_memalloc(sizeof(t_stone));
    new->room_name = inf->start;
    lst_add_back(route->path, lstnew(new));
    new = (t_stone*)ft_memalloc(sizeof(t_stone));
    new->room_name = inf->end;
    lst_add_back(route->path, lstnew(new));
    lst_add_back(inf->routestmp, lstnew(route));
    inf->numofpath++;
}


//check to see if end node of a given map is adjacent to the start node
//if yes, inlucde that path into inf->routestmp, inf->numofpath++
void    checkspecial(t_sto *inf)
{
    if (isendadj(inf))
        addsepath(inf);
}