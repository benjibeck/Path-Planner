#include "lem_in.h"

int     *newant(int antnum) //dont forget to free the memory
{
    int *newant;

    newant = (int*)ft_memalloc(sizeof(int));
    *newant = antnum;
    return (newant);
}


void    moveant(t_sto *inf)
{
    // ft_putendl("into moveant");
    //go to all array of valid path
    //pull the first ant (which are waiting) from queue, and add to room
    int i;
    int space;
    t_lst *tmp;
    int *anttmp;
    // int antnametmp;

    // printf("antarrive = %d , infant = %d\n", inf->antarrive, inf->ant);

    while (inf->antarrive != inf->ant) //do the following operation until all ants reach destination
    {
        // printf("antarrive = %d , infant = %d\n", inf->antarrive, inf->ant);
        // printf("antariive = %d\n", inf->antarrive);
        //whenever there is an ant arrive at the end
        //increment the number of ant arrive!
        i = 0;
        space = 0;
        // printf("num of path: %d\n", inf->numofpath);
        while (i < inf->usedpaths && inf->antarrive != inf->ant)
        {
            // ft_putendl("moveant 2 loop");
            tmp = *(inf->routes[i]->path);
            while (tmp && inf->antarrive != inf->ant)
            {
                // ft_putendl("moveant 3loop");
                if (tmp->next && ((t_stone*)(tmp->next->content))->ant_name) {
                    ((t_stone*)(tmp->content))->ant_name = ((t_stone*)(tmp->next->content))->ant_name;
                }
                else if (tmp->next == NULL && !isempty_q(inf->routes[i]->ant))
                {
                    anttmp = (int*)pull_q(inf->routes[i]->ant);
                    ((t_stone*)(tmp->content))->ant_name = *anttmp;
                    free(anttmp);
                    // ((t_stone*)(tmp->content))->ant_name = *(int*)pull_q(inf->routes[i]->ant);
                    // ((t_stone*)(tmp->content))->ant_name = *(int*)pull_q(inf->routes[i]->ant);
                }
                else if (isempty_q(inf->routes[i]->ant)) {
                    ((t_stone*)(tmp->content))->ant_name = 0;
                }
                //print instruction
                if (((t_stone*)(tmp->content))->ant_name)
                {
                    //increment antarrive
                    if (tmp == *(inf->routes[i]->path))
                        inf->antarrive++;
                    if (ft_strcmp(((t_stone*)(tmp->content))->room_name, inf->start))
                    {
                        if (space)
                            printf(" ");
                        printf("L%d-%s", ((t_stone*)(tmp->content))->ant_name, ((t_stone*)(tmp->content))->room_name);
                        space++;
                    }
                }
                tmp = tmp->next;
            }
            //the function to move all the ants in that path (rooms) forward
            i++;
            //also inf->antarrive++ whenever there is ant reach the destination
        }
        // write(1, "\n", 1);
        printf("\n");
    }
}

void    printant(t_sto *inf)
{
    //print the name of ant in each queue
    int i = 0;
    t_lst *tmp;

    //4
    // printf("nop = %d\n", inf->numofpath);
    while (i < inf->usedpaths)
    {
        // ft_putendl("pa outer loop");
        tmp = inf->routes[i]->ant->first;
        while (tmp)
        {
            printf("an = %d, ", *(int*)tmp->content);
            tmp = tmp->next;
        }
        printf("\n");
        i++;
    }
}

void printroutes(t_sto *inf)
// void printroutes(t_eachpath **routes)
{
    t_lst *tmp;

    int i = 0;
    while (i < inf->usedpaths)
    {
        tmp = *(inf->routes[i]->path);
        while (tmp)
        {
            printf("%s<", ((t_stone*)tmp->content)->room_name);
            tmp = tmp->next;
        }
        printf("\n");
        i++;
    }
}

void    addant(t_sto *inf)
{
    //inf->ant
    int i;
    int antname;
    int antnumtmp;

    antnumtmp = inf->ant;
    i = 0;
    antname = 1;
    while (antnumtmp)
    {
        i = 0;
        while (i < inf->numofpath && antnumtmp)
        {
            if (i != 0 && (inf->routes[i]->distance >= inf->routes[i-1]->distance))
                break;
            if (inf->routes[i]->ant == 0)
            {
                inf->routes[i]->ant = init_q();
                inf->usedpaths++;
            }
            add_q(inf->routes[i]->ant, newant(antname));
            antnumtmp--;
            inf->routes[i]->distance++;
            antname++;
            i++;
        }
    }
    // printant(inf);
    // printroutes(inf);
}