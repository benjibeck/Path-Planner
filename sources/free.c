#include "lem_in.h"


void freemap(t_sto *inf)
{
	t_lst *tmp = (*(inf->rooms));
	t_lst *tmp2 = tmp;
	t_lst *tmp3;
	t_lst *tmp4;

	while(tmp != NULL)
	{
		tmp = tmp->next;
		free(((t_room*)(tmp2->content))->name);
		tmp3 = (*(((t_room*)(tmp2->content))->adj));
		while (tmp3)
		{
			tmp4 = tmp3;
			tmp3 = tmp3->next;
			free(tmp4->content);
			free(tmp4);
		}
		free((((t_room*)(tmp2->content))->adj));
		free(((t_room*)(tmp2->content)));
		free(tmp2);
		tmp2 = tmp;
	}
}

void freepath(t_sto *inf)
{
    t_lst *tmp;
    t_lst *tmp2;
    int i = 0;

    while (i < inf->numofpath)
    {
        tmp = *(inf->routes[i]->path);
        while (tmp)
        {
            tmp2 = tmp;
            tmp = tmp->next;
            free(tmp2->content);
            free(tmp2);
        }
        free(inf->routes[i]->ant);
        free(inf->routes[i]->path); //t_lst**
        free(inf->routes[i]);
        i++;
    }
    free(inf->routes);
}

void	freeall(t_sto *inf)
{
    freemap(inf);
    freepath(inf);
	//free for bfs
	free(inf->rooms);
	free(inf->start);
	free(inf->end);
	free(inf->edges);
	free(inf);
}