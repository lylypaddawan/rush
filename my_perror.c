/*
** my_perror.c for grimly in /home/corjon_l//rush/rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Fri Mar  1 22:20:01 2013 lysandre corjon
** Last update Fri Mar  1 22:23:58 2013 lysandre corjon
*/

#include <string.h>

void	my_perror(char *str)
{
  write(2, str, strlen(str));
}
