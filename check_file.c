/*
** check_file.c for grimly in /home/corjon_l//rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Fri Mar  1 20:54:16 2013 lysandre corjon
** Last update Sat Mar  2 23:18:13 2013 lysandre corjon
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "grimly.h"

int	check_tab(char **tab, t_info **info)
{
  int	x;
  int	y;

  for (y = 0; y < (*info)->heigth; y++)
    {
      for (x = 0; x < (*info)->width; x++)
	{
	  if (x == 0 || x == ((*info)->width - 1) || y == 0 || y == ((*info)->heigth - 1))
	    {
	      if (tab[y][x] != '1' && tab[y][x] != '2' && tab[y][x] != '*')
		{
		  my_perror("MAP ERROR\n");
		  return (-2);
		}
	    }
	  if (tab[y][x] != '1' && tab[y][x] != '2' && tab[y][x] != ' ' && tab[y][x] != '*')
	    {
	      my_perror("MAP ERROR\n");
	      return (-1);
	    }
	}
    }
  return (0);
}

t_ll	*feel_ll(t_ll *file, char *str)
{
  t_ll	*tmp;
  t_ll	*new;

  tmp = file;
  if (tmp == NULL)
    {
      if ((new = malloc(sizeof(*file))) == NULL)
	return (NULL);
      if ((new->data = strdup(str)) == NULL)
	return (NULL);
      new->next = NULL;
      file = new;
    }
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      if ((new = malloc(sizeof(*file))) == NULL)
	return (NULL);
      if ((new->data = strdup(str)) == NULL)
	return (NULL);
      new->next = NULL;
      tmp->next = new;
    }
  return (file);
}

char	**put_ll_to_tab(t_info **info, int count, char **tab, t_ll *file)
{
  if ((count - 1) != (*info)->heigth)
    {
      my_perror("MAP ERROR\n");
      return (NULL);
    }
  if ((tab = malloc((count) * sizeof(*tab))) == NULL)
    {
      my_perror("Malloc Fail\n");
      return (NULL);
    }
  tab[count - 1] = NULL;
  count = 0;
  while (file != NULL)
    {
      tab[count++] = file->data;
      if ((int)strlen(file->data) != (*info)->width)
	{
	  my_perror("MAP ERROR\n");
	  return (NULL);
	}
      file = file->next;
    }
  free_list(file);
  return (tab);
}

char	**get_file_in_tab(int fd, t_info **info)
{
  int	count;
  char	*str;
  char	**tab;
  t_ll	*file;

  count = 1;
  tab = NULL;
  file = NULL;
  if ((str = get_next_line(fd)) == NULL)
    return (NULL);
  if ((info = get_tall(str, info)) == NULL)
    return (NULL);
  free(str);
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((file = feel_ll(file, str)) == NULL)
	return (NULL);
      free(str);
      count++;
     }
  if ((tab = put_ll_to_tab(info, count, tab, file)) == NULL)
    return (NULL);
  return (tab);
}

char	**check_file(char *str, t_info **info)
{
  char	**tab;
  int	fd;
  
  if (is_file(str) != 0)
    {
      my_perror("MAP ERROR\n");
      return (NULL);
    }
  if ((fd = open(str, O_RDONLY)) == -1)
     {
       my_perror("MAP ERROR\n");
       return (NULL);
     }
  if ((tab = get_file_in_tab(fd, info)) == NULL)
    return (NULL);
  if (check_tab(tab, info) != 0 || get_info(info, tab) != 0)
    return (NULL);
  if (close(fd) != 0)
    {
      my_perror("fclose error\n");
      return (NULL);
    }
  return (tab);
}
