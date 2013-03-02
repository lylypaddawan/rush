/*
** grimly.c for grimly in /home/lacave_a//afs/Rush/rush2
** 
** Made by paul-auguste lacave
** Login   <lacave_a@epitech.net>
** 
** Started on  Fri Mar  1 20:44:39 2013 paul-auguste lacave
** Last update Sat Mar  2 17:15:29 2013 lysandre corjon
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

  if ((info = malloc(sizeof(*info))) == NULL)
    {
      my_perror("Malloc Fail\n");
      return (-1);
    }
  if (av[1][0] == '-' && av[1][1] == 'f')
    {

      if (check_name(av[2]) == 1)
	tab = check_file(av[2], &info);
      else
	printf("Fail name of map !\n");
      
    }
  while (tab[i] != NULL)
    printf("%s\n", tab[i++]);
  printf("width : %d | height : %d\n", info->width, info->height);
  return (0);
}
