/*
** my_perror.c for grimly in /home/corjon_l//rush/rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Fri Mar  1 22:20:01 2013 lysandre corjon
** Last update Sat Mar  2 17:10:37 2013 lysandre corjon
*/

#include <string.h>
#include <unistd.h>

void	my_perror(char *str)
{
  write(2, str, strlen(str));
}
