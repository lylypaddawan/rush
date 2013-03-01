/*
** check_file.c for grimly in /home/corjon_l//rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Fri Mar  1 20:54:16 2013 lysandre corjon
** Last update Fri Mar  1 22:46:05 2013 lysandre corjon
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	is_file(char *str)
{
  if (access(str, F_OK) != 0)
    return (-1);
  if (access(str, R_OK) != 0)
    return (-1);
  return (0);
}

char	**get_file_in_tab(int fd)
{
  char	*str;
  char	**tab;

  tab = NULL;
  while ((str = get_next_line(fd)) != NULL)
    printf("%s\n", str);
}

char	**check_file(char *str)
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
  if ((tab = get_file_in_tab(fd)) == NULL)
    return (NULL);
  if (close(fd) != 0)
    {
      my_perror("fclose error\n");
      return (NULL);
    }
  return (tab);
}
