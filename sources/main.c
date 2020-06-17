/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:50:33 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/28 17:50:35 by kmaneera         ###   ########.fr       */
/* ************************************************************************** */

#include "lem_in.h"
t_sto *ini_inf(void)
{
	t_sto *inf;

	if (!(inf = (t_sto*)ft_memalloc(sizeof(t_sto))))
		errexit("Error! Cannot allocate memory");
	if (!(inf->rooms = (t_lst**)ft_memalloc(sizeof(t_lst*))))
		errexit("Error! Cannot allocate memory");
	if (!(inf->edges = (t_lst**)ft_memalloc(sizeof(t_lst*))))
		errexit("Error! Cannot allocate memory");
	if (!(inf->routestmp = (t_lst**)ft_memalloc(sizeof(t_lst*))))
		errexit("Error! Cannot allocate memory");
	return (inf);
}

int		checkinf(t_sto *inf)
{
	if (!(inf->ant) || !(inf->start) || !(inf->end))
		return (1);
	return (0);
}

void	errexit(char *str)
{
	write(1, "\e[91m", 5);
	ft_putendl(str);
	exit(1);
}

int		main()
{
	t_sto *inf;

	inf = ini_inf();
	readmap(inf);
	if (checkinf(inf))
		errexit("Error, primary values not found!");
	checkspecial(inf);
	discover(inf);
	addant(inf);
	moveant(inf);
	freeall(inf);
	system("leaks -s lem_in");
}
