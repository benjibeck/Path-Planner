#include "lem_in.h"

//jot the link btw room into DLL
void    jot_edge(t_sto *inf, char *h, char *t, int val)
{
    t_edge  *new;

    if (!(new = (t_edge*)ft_memalloc(sizeof(t_edge))))
        errexit("Cannot allocate memory!");
    //doesn't need to malloc, just use what already have
    new->head = h;
    new->tail = t;
    new->bfsindex = val;
    lst_add(inf->edges, lstnew(new));
}

void    freeedge(t_sto *inf)
{
    t_lst *tmp;
    t_lst *tmp2;

    tmp = *(inf->edges);
    while (tmp)
    {
        tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2->content);
        free(tmp2);
    }
}

void    printedge(t_sto *inf)
{
    t_lst *tmp;

    tmp = *(inf->edges);
    while (tmp)
    {
        printf("%s:%s > %d\n", ((t_edge*)(tmp->content))->head,\
                                ((t_edge*)(tmp->content))->tail,\
                                ((t_edge*)(tmp->content))->bfsindex);
        tmp = tmp->next;
    }
}