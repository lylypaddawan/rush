/*
** algo.c for grimly in /home/corjon_l//rush/rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Sun Mar  3 03:24:57 2013 lysandre corjon
** Last update Sun Mar  3 03:50:51 2013 lysandre corjon
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "grimly.h"

int	go_algo(t_info *info)
{
  t_pt	*point;

  point = info->point;
  while (point != NULL)
    {
      if (point->type == ENTRY)
	printf("type : Entry\nx = %d_ny = %d\n\n", point->x + 1, point->y + 1);
      else if (point->type == EXIT)
	printf("type : Exit\nx = %d_ny = %d\n\n", point->x + 1, point->y + 1);
      point = point->next;
    }
  info->resp = strdup("caca");
  return (0);
}
