/*
** info.c for grimly in /home/corjon_l//rush/rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Sat Mar  2 22:42:52 2013 lysandre corjon
** Last update Sat Mar  2 23:27:41 2013 lysandre corjon
*/

#include <stdlib.h>
#include "grimly.h"

t_pt	*get_pos(t_pt *pt, char c, int x, int y)
{
  t_pt	*new;
  t_pt	*tmp;

  tmp = pt;
  if ((new = malloc(sizeof(*new))) == NULL)
    {
      my_perror("Malloc Fail\n");
      return (NULL);
    }
  new->x = x;
  new->y = y;
  new->next = NULL;
  if (tmp == NULL)
    tmp = new;
  else
    {
      while (pt->next != NULL)
	pt = pt->next;
      pt->next = new;
    }
  if (c == '1')
    new->type = ENTRY;
  else
    new->type = EXIT;
  return (tmp);
}

int	get_entry(t_info **info, char **tab)
{
  int	x;
  int	y;
  t_pt	*tmp;

  tmp = NULL;
  for (y = 0; y < (*info)->heigth; y++)
    {
      for (x = 0; x < (*info)->width; x++)
	{
	  if (tab[y][x] == '1' || tab[y][x] == '2')
	    {
	      if ((tmp = get_pos(tmp, tab[y][x], x, y)) == NULL)
		return (-1);
	    }
	}
    }
  (*info)->point = tmp;
  x = 0;
  y = 0;
  while (tmp != NULL)
    {
      if (tmp->type == ENTRY)
	x++;
      else if (tmp->type == EXIT)
	y++;
      tmp = tmp->next;
    }
  if (x < 1 || y < 1)
    {
      my_perror("MAP ERROR\n");
      return (-2);
    }
  return (0);
}
