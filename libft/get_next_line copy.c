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

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;

	if (!s || !(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp = str;
	while (start--)
		s++;
	while (len--)
		*(str++) = *(s++);
	*str = '\0';
	return (tmp);
}

char	*ft_strdup(const char *s)
{
	int		a;
	char	*destination;

	a = 0;
	if (!(destination = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[a])
	{
		destination[a] = s[a];
		a++;
	}
	destination[a] = '\0';
	return (destination);
}

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_strdel(char **as)
{
	ft_memdel((void**)as);
}

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

void	ft_bzero(void *s, size_t len)
{
	unsigned char *tmp;

	tmp = (unsigned char*)s;
	while (len--)
		*(tmp++) = 0;
}

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (!(tmp = (void*)malloc(size)))
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}

size_t	ft_strlen(const char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int a;

	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	char *tmp;

	tmp = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *result;

	if ((!(s1)) || (!(s2)) ||
		!(result = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	result = ft_strcpy(result, s1);
	result = ft_strcat(result, s2);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c && *s && c)
		return (char*)(s);
	else
		return (NULL);
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
