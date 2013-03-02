/*
** check_file.c for grimly in /home/corjon_l//rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Fri Mar  1 20:54:16 2013 lysandre corjon
** Last update Sat Mar  2 17:36:08 2013 lysandre corjon
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
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
  (*info)->height = atoi(&str[++i]);
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

char	**put_ll_to_tab(int count, char **tab, t_ll *file)
{
  if ((tab = malloc((count) * sizeof(*tab))) == NULL)
    return (NULL);
  tab[count - 1] = NULL;
  count = 0;
  while (file != NULL)
    {
      tab[count++] = file->data;
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
  if ((tab = put_ll_to_tab(count, tab, file)) == NULL)
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
  if (close(fd) != 0)
    {
      my_perror("fclose error\n");
      return (NULL);
    }
  return (tab);
}
