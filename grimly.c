/*
** grimly.c for grimly in /home/lacave_a//afs/Rush/rush2
** 
** Made by paul-auguste lacave
** Login   <lacave_a@epitech.net>
** 
** Started on  Fri Mar  1 20:44:39 2013 paul-auguste lacave
** Last update Sun Mar  3 03:32:06 2013 lysandre corjon
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grimly.h"

int	check_name(char *name)
{
  int	a;

  a = strlen(name);
  if (strcmp(".map", &name[a - 4]) == 0)
    return (1);
  else
    return (0);
}

int	deploy_algo(char **tab, t_info *info)
{
  int	i;
  t_pt	*point;

  i = 0;
  info->resp = NULL;
  while (tab[i] != NULL)
    printf("%s\n", tab[i++]);
  printf("width : %d | heigth : %d\n", info->width, info->heigth);
  point = info->point;
  while (point->next != NULL)
    {
      point->map = tab_cpy(tab);
      point = point->next;
    }
  point->map = tab;
  while (info->resp == NULL)
    {
      if (go_algo(info) != 0)
	{
	  my_perror("MAP ERROR\n");
	  return (-1);
	}
    }
  return (0);
}

int	main(int ac, char **av)
{
  t_info	*info;
  char		**tab;

  if (ac == 3)
    {
      if ((info = malloc(sizeof(*info))) == NULL)
	{
	  my_perror("Malloc Fail\n");
	  return (-1);
	}
      if (strcmp("-f", av[1]) == 0)
	{
	  if (check_name(av[2]) == 1)
	    {
	      if ((tab = check_file(av[2], &info)) == NULL)
		return (-2);
	      if (deploy_algo(tab, info) != 0)
		return (-3);
	    }
	  else
	    {
	      printf("MAP ERROR\n");
	      return (-1);
	    }	  
	}
    }
  else
    {
      if (put_usage() != 0)
	return (-1);
    }
  return (0);
}
