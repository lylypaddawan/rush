/*
** check_file.c for grimly in /home/corjon_l//rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Fri Mar  1 20:54:16 2013 lysandre corjon
** Last update Fri Mar  1 21:30:30 2013 lysandre corjon
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fctnl.h>
#include <unistd.h>

int	is_file(char *str)
{
  if (acces(str, F_OK, R_OK) != 0)
    return (-1);
  return (0);
}

char	**check_file(char *str)
{
  int	fd;

  if (is_dir(str) == 0)
    {
      my_perror("MAP ERROR\n");
      return (NULL);
    }
  if ((fd = open(str, O_RDONLY)) == -1)
    {
      my_perror("MAP ERROR\n");
      return (NULL);
    }
}
