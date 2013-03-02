/*
** grimly.c for grimly in /home/lacave_a//afs/Rush/rush2
** 
** Made by paul-auguste lacave
** Login   <lacave_a@epitech.net>
** 
** Started on  Fri Mar  1 20:44:39 2013 paul-auguste lacave
** Last update Sat Mar  2 19:16:24 2013 paul-auguste lacave
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grimly.h"

int	check_name(char *name)
{
  int	a;

  a = strlen(name);
  if (name[a-1] == 'p' && name[a-2] == 'a' && name[a-3] == 'm' && name[a-4] == '.')
    return (1);
  else
    return (0);
}

int	main(int ac, char **av)
{
  int		i;
  t_info	*info;
  char		**tab;
  
  if (ac == 3)
    {
      if ((info = malloc(sizeof(*info))) == NULL)
	{
	  my_perror("Malloc Fail\n");
	  return (-1);
	}
      if (av[1][0] == '-' && av[1][1] == 'f')
	{
	  if (check_name(av[2]) == 1)
	    {
	      if ((tab = check_file(av[2], &info)) == NULL)
		return (-2);
	    }
	  else
	    {
	      printf("Fail name of map !\n");
	      return (-1);
	    }	  
	}
      while (tab[i] != NULL)
	printf("%s\n", tab[i++]);
      printf("width : %d | heigth : %d\n", info->width, info->heigth);
    }
  return (0);
}
