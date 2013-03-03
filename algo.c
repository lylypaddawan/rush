/*
** algo.c for grimly in /home/corjon_l//rush/rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Sun Mar  3 03:24:57 2013 lysandre corjon
** Last update Sun Mar  3 03:32:20 2013 lysandre corjon
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "grimly.h"

int	go_algo(t_info *info)
{
  static int	i = 0;

  if (i == 7)
    info->resp = strdup("caca");
  printf("lol\n");
  sleep(1);
  i++;
  return (0);
}
