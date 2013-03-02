/*
** tools.c for grimly in /home/corjon_l//rush/rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Sat Mar  2 20:29:28 2013 lysandre corjon
** Last update Sat Mar  2 20:32:33 2013 lysandre corjon
*/

#include <stdlib.h>
#include <unistd.h>
#include "grimly.h"

int	is_file(char *str)
{
  if (access(str, F_OK) != 0)
    return (-1);
  if (access(str, R_OK) != 0)
    return (-1);
  return (0);
}

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void	free_list(t_ll *list)
{
  t_ll	*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
}

t_info	**get_tall(char *str, t_info **info)
{
  int	i;

  i = 0;
  while (str[i] != 'x')
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  my_perror("MAP ERROR\n");
	  return (NULL);
	}
      i++;
    }
  (*info)->width = atoi(str);
  (*info)->heigth = atoi(&str[++i]);
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  my_perror("MAP ERROR\n");
	  return (NULL);
	}
      i++;
    }
  return (info);
}
