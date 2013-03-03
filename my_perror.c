/*
** my_perror.c for grimly in /home/corjon_l//rush/rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Fri Mar  1 22:20:01 2013 lysandre corjon
** Last update Sun Mar  3 02:49:50 2013 lysandre corjon
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	put_usage()
{
  if (printf("./grimly -f map_name.map\n") < 0)
    return (-1);
  return (0);
}

void	my_perror(char *str)
{
  write(2, str, strlen(str));
}
