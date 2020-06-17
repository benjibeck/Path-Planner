#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# include <stdio.h>

# define NORMAL_R 0
# define START_R 1
# define END_R   2
# define ANT 0
# define ROOM 1
# define LINKS 2


typedef struct s_queue
{
	struct s_lst *first;
	struct s_lst *last;

}				t_queue;

typedef struct s_stack
{
	struct s_lst *top;

}				t_stack;

typedef struct	s_lst
{
	void		*content;
	struct s_lst *next;
}				t_lst;

typedef struct	s_eachpath
{
	int			distance;
	t_lst		**path;
	t_queue		*ant;
	int			antfinish;
}				t_eachpath;

typedef struct	s_stone
{
	char		*room_name;
	int			ant_name;
}				t_stone;


typedef struct	s_edge
{
	char		*head;
	char		*tail;
	int			bfsindex;
}				t_edge;

typedef	struct	s_room
{
	char		*name;
	int			y;
	int			x;
	int 		visited;
	t_lst		**adj;
}				t_room;

typedef struct	s_sto
{
	int			count;
	t_lst		**rooms;
	char		*start;
	char		*end;

	t_queue		*tbvisited;
	t_queue		*helpq;
	t_lst		**edges;
	t_eachpath	**routes;
	t_lst		**routestmp;
	
	int			numofpath;
	int			usedpaths;
	int			ant;
	int			antarrive;
	int			start_isget;
	int			end_isget;
	int			numofpath_isget;
	int			roomtype;
	int			readphase;
}				t_sto;

#endif

//main
void	freeall(t_sto *inf);

//utils
void	errexit(char *str);
void	test(t_sto *inf);

//map
void    readmap(t_sto *inf);
int    read_links(t_sto *inf, char *line);

void    addant(t_sto *inf);
void	moveant(t_sto *inf);

//special
void    checkspecial(t_sto *inf);

//bfs
int			bfs(t_sto *inf);
void  discover(t_sto *inf);

//edge
void    jot_edge(t_sto *inf, char *h, char *t, int val);
void    freeedge(t_sto *inf);
void    printedge(t_sto *inf);

//path
void    jot_edge(t_sto *inf, char *h, char *t, int val);
void    printpath(t_lst **path);
void    printedge(t_sto *inf);
t_eachpath   *geteachpath(t_sto* inf, t_lst *cand);
void    freeedge(t_sto *inf);

//list
void	lst_del_join_spe(t_lst **alst, t_lst *new);
void	lst_add_back(t_lst **alst, t_lst *new);
t_lst	*just_add_back(t_lst **alst);
void	lst_add_check(t_lst **alst, t_lst *new);
void	lst_add(t_lst **alst, t_lst *new);
void	lst_del_join(t_lst **alst, t_lst *new);
t_lst	*lstnew(void *content);
void	lst_del_lastelem(t_lst **alst);

//link
int     get_link(t_sto *inf, char **line_elems);
int     check_link(t_sto *inf, char *line);

//se
int    get_se(t_sto *inf);
int     check_se(t_sto *inf, char *line);

//room
int  check_room(t_sto *inf, char *line);

//queue
t_queue *init_q(void);
void add_q(t_queue *queue, void *content);
void *pull_q(t_queue *queue);
void *peek_q(t_queue *queue);
int isempty_q(t_queue *queue);

//stack
t_stack	*init_stack(void);
void	add_stack(t_stack *stack, void *content);
void	*pull_stack(t_stack *stack);
int		isempty_stack(t_stack *stack);