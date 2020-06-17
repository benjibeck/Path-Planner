/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:57:23 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/13 13:00:05 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 32
#define FD 1024

static int		gnlhelper(char **line, char **aline, char *alinetmp, int *n)
{
	if (n[0] < 0)
		return (-1);
	else if (!n[0] && !*aline)
		return (0);
	else
	{
		n[1] = 0;
		while ((*aline)[n[1]] && (*aline)[n[1]] != '\n')
			n[1]++;
		if ((*aline)[n[1]] == '\n')
		{
			*line = ft_strsub((*aline), 0, n[1]);
			alinetmp = ft_strdup((*aline) + n[1] + 1);
			ft_strdel(aline);
			*aline = alinetmp;
			if (!**aline)
				ft_strdel(aline);
		}
		else
		{
			*line = ft_strsub(*aline, 0, n[1]);
			ft_strdel(aline);
		}
		return (1);
	}
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*aline[FD];
	int			n[2];
	char		*alinetmp;

	if (!line || fd < 0)
		return (-1);
	while (((n[0] = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[n[0]] = '\0';
		if (!aline[fd])
			aline[fd] = ft_strdup(buf);
		else
		{
			alinetmp = ft_strjoin(aline[fd], buf);
			free(aline[fd]);
			aline[fd] = alinetmp;
		}
		if (ft_strchr(aline[fd], '\n'))
			break ;
	}
	return (gnlhelper(line, &aline[fd], alinetmp, n));
}
