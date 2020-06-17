/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:58 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/29 19:22:01 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"   
#include <unistd.h>

// void	test(t_sto *inf)
// {
// 	printf("\033[1;34m");
// 	t_lst *tmp = (*(inf->rooms));
// 	t_lst *tmp2;
// 	printf("ant = %d\n", inf->ant);
// 	printf("startroom = %s\n", inf->start);
// 	printf("endroom = %s\n\n", inf->end);

// 	while (tmp)
// 	{
// 		printf("room = %s ", ((t_room*)(tmp->content))->name);
// 		printf("%d:", ((t_room*)(tmp->content))->x);
// 		printf("%d	", ((t_room*)(tmp->content))->y);
// 		tmp2 = tmp;
// 		tmp2 = *(((t_room*)(tmp->content))->adj);
// 		while (tmp2) //print adj list of each room
// 		{
// 			printf("%s,", (char*)tmp2->content);
// 			tmp2 = tmp2->next;
// 		}

// 		printf("\n");
// 		tmp = tmp->next;
// 	}
// 	printf("\033[0m");
// 	printf("\n");
// }

