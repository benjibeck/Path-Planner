/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:37:55 by kmaneera          #+#    #+#             */
/*   Updated: 2020/03/07 17:38:08 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// check if the given room has been visited or not, return the index, if not, mark visited
int   is_visited(t_sto *inf, char *tofind, int parentval, char *parentname)
{
   t_lst *tmp;

   tmp = *(inf->rooms);
   while (tmp)
   {
      if (ft_strcmp(((t_room*)tmp->content)->name, tofind) == 0)
      {
         if (((t_room*)tmp->content)->visited && ft_strcmp(tofind, inf->end)) //!0 > visited + not endroom > skip
         {
            return (1);
         }
         else //also add edge into DLL
         {
            add_q(inf->helpq, tmp); //add the pointer to that room into helper LL as well
            jot_edge(inf, parentname, tofind, parentval + 1);
            ((t_room*)tmp->content)->visited = parentval + 1;
            if (ft_strcmp(tofind, inf->end) == 0)
               return (-1);
            return (0);
         }
      }
      tmp = tmp->next;
   }
   errexit("There is an invalid room in adjacency list!");
   return (-1);
}

int   findadjroom(t_sto *inf, char *tofind)
{
   t_lst *tmp;
   t_lst *tmp2;
   int   iv_ret;

   tmp = *(inf->rooms);
   while (tmp)
   {
      if (ft_strcmp(((t_room*)tmp->content)->name, tofind) == 0)
         {
            tmp2 = (*(((t_room*)(tmp->content))->adj));
            while (tmp2)
            {
               iv_ret = is_visited(inf, (char*)tmp2->content, ((t_room*)tmp->content)->visited, tofind);
               if (iv_ret == 0)
                  add_q(inf->tbvisited, (char*)tmp2->content);
               else if (iv_ret == -1) //signalling that end room is discovered!
                  return (1);
               tmp2 = tmp2->next;
            }
            break;
         }
      tmp = tmp->next;
   }
   return (0);
}

int    bfs(t_sto *inf)
{
    char *cr; //current room    
    //put the name of start room into the queue
   inf->tbvisited = init_q(); 
   inf->helpq = init_q();
   add_q(inf->tbvisited, inf->start); //doesn't malloc, so that it can be freed only once
   is_visited(inf, inf->start, 0, 0);
   while (isempty_q(inf->tbvisited) == 0)
   {
      cr = pull_q(inf->tbvisited);

      if (ft_strcmp(cr, inf->end))
      {
         if  ((findadjroom(inf, cr))) //if it return sth, means end room is spotted!
         {
            while (!(isempty_q(inf->tbvisited)))
            {
               pull_q(inf->tbvisited);
            }
            free(inf->tbvisited);
            return (1);
         }
      }
   }
   free(inf->tbvisited);
   return (0);
}





void  resetbfs(t_sto *inf)
{
   //reset vsindex of all the room, excluding the rooms are identified as parts of valid path
   t_lst *fhq; //from help queue
   t_lst *tmp;
   t_lst *currentroute;

   currentroute = just_add_back(inf->routestmp);
   tmp = *(((t_eachpath*)currentroute->content)->path);
   while (isempty_q(inf->helpq) == 0)
   {
      fhq = pull_q(inf->helpq);
      if ((ft_strcmp(((t_room*)fhq->content)->name, ((t_room*)tmp->content)->name)) == 0)
      {
         if ((ft_strcmp(inf->start, ((t_room*)tmp->content)->name) == 0) || (ft_strcmp(inf->end, ((t_room*)tmp->content)->name) == 0))
            ((t_room*)(fhq->content))->visited = 0;
         if (tmp->next)
            tmp = tmp->next;
      }
      else
      {
         ((t_room*)(fhq->content))->visited = 0;
      }
   }
   free(inf->helpq);
}


void  revpath(t_sto *inf)
{
   t_stack *stack;
   t_lst *pathtmp;
   t_lst *stonetmp;

   stack = init_stack();
   pathtmp = *(inf->routestmp);
   while (pathtmp)
   {
      stonetmp = (*(((t_eachpath*)(pathtmp->content))->path));
      while (stonetmp)
      {
         add_stack(stack, (((t_stone*)stonetmp->content)->room_name));
         stonetmp = stonetmp->next;
      }
      stonetmp = *(((t_eachpath*)(pathtmp->content))->path);
      while (stonetmp)
      {
         ((t_stone*)stonetmp->content)->room_name = pull_stack(stack);
         stonetmp = stonetmp->next;
      }
      pathtmp = pathtmp->next;
   }
   free(stack);
}

//converting LL of valid path into arr, making it compatible with moveant
void  lltoarr(t_sto *inf)
{
   int i;
   t_lst *tmp;
   t_lst *tmp2;
   inf->routes = (t_eachpath**)ft_memalloc(sizeof(t_eachpath*) * inf->numofpath);

   i = 0;
   tmp = *(inf->routestmp);
   while (i < inf->numofpath)
   {
      tmp2 = tmp;
      tmp = tmp->next;
      inf->routes[i] = tmp2->content;
      free(tmp2);
      i++;
   }
   free(inf->routestmp);
}


void  clearq(t_sto *inf)
{
   while (isempty_q(inf->helpq) == 0)
      pull_q(inf->helpq);
   free(inf->helpq);
}
//the main function for discovering all rooms
//
void  discover(t_sto *inf)
{
   t_eachpath *tmppath;
   while (bfs(inf))
   {
      // printedge(inf);
      if ((tmppath = geteachpath(inf, *(inf->edges))))
      {
         inf->numofpath++;
         lst_add_back(inf->routestmp, lstnew(tmppath));
      }
      else
         errexit("Cannot trace back the route");
      resetbfs(inf);
   }
   if (!inf->numofpath)
      errexit("There is no valid path!");
   clearq(inf);
   freeedge(inf); //free only edges, as a data structure, not includes roomname, stored in main <t_lst**rooms>
   revpath(inf);
   lltoarr(inf);
}