/*
** get_next_line.c for get_next_line in /home/corjon_l//projets/get_next_line
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Wed Dec 12 17:50:14 2012 lysandre corjon
** Last update Fri Mar  1 22:44:20 2013 lysandre corjon
*/

#include <unistd.h>
#include <stdlib.h>
#include "grimly.h"

int	mem_ret(char *ret[1], char *save, char *tmp, int ret_len)
{
  int	i;
  int	save_len;

  save_len = 0;
  while (save[save_len] != '\0' && save[save_len] != '\n')
    save_len += 1;
  ret[0] = malloc(sizeof(**ret) * (ret_len + save_len + 1));
  if (ret[0] == NULL)
    return (-1);
  i = 0;
  while (i < ret_len)
    {
      ret[0][i] = tmp[i];
      i += 1;
    }
  i = 0;
  while (i < save_len)
    {
      ret[0][i + ret_len] = save[i];
      i += 1;
    }
  free(tmp);
  ret[0][i + ret_len] = '\0';
  return ((save[i] == '\n'));
}

int	add_save(char *ret[1], char *save)
{
  char	*tmp;
  int	ret_len;
  int	i;

  if (save[0] == '\0')
    return (0);
  ret_len = 0;
  while (ret[0][ret_len])
    ret_len += 1;
  tmp = malloc(sizeof(*tmp) * (ret_len + 1));
  if (tmp == NULL)
    return (-1);
  i = 0;
  while (i <= ret_len)
    {
      tmp[i] = ret[0][i];
      i += 1;
    }
  free(*ret);
  return (mem_ret(ret, save, tmp, ret_len));
}

void	evolve_save(char *save)
{
  int	i;

  while (save[0] != '\0' && save[0] != '\n')
    {
      i = 0;
      while (save[i] != '\0')
	{
	  save[i] = save[i + 1];
	  i ++;
	}
    }
  i = 0;
  while (save[i] != '\0')
    {
      save[i] = save[i + 1];
      i ++;
    }
}

char		*get_next_line(const int fd)
{
  static char	save[READ_LEN + 1];
  char		*ret[1];
  int		val_ret;

  if (READ_LEN <= 0)
    return (NULL);
  ret[0] = malloc(sizeof(**ret));
  if (ret[0] == NULL)
    return (NULL);
  ret[0][0] = '\0';
  while ((val_ret = add_save(ret, save)) != 1)
    {
      if (val_ret == -1)
      	return (NULL);
      save[read(fd, save, READ_LEN)] = '\0';
      if (save[0] == '\0')
	{
	  free(ret[0]);
	  return (NULL);
	}
    }
  evolve_save(save);
  return (ret[0]);
}
