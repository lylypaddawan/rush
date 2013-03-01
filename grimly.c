/*
** grimly.c for grimly in /home/lacave_a//afs/Rush/rush2
** 
** Made by paul-auguste lacave
** Login   <lacave_a@epitech.net>
** 
** Started on  Fri Mar  1 20:44:39 2013 paul-auguste lacave
** Last update Fri Mar  1 21:28:13 2013 paul-auguste lacave
*/

#include <stdio.h>
#include <string.h>

int	check_name(char *name)
{
  int	a;

  a = strlen(name);
  if (name[a-1] == 'p' && name[a-2] == 'a' && name[a-3] == 'm' && name[a-4] == '.' && name[a-5] != '\0')
    return (1);
  else
    return (0);
}

int	main(int ac, char **av)
{
  if (av[1][0] == '-' && av[1][1] == 'f')
    {

      if (check_name(av[2]) == 1)
	check_file(av[2]);
      else
	printf("Fail name of map !\n");
      
    }
  return (0);
}
