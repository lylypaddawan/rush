/*
** others.c for grimly in /home/corjon_l//rush/rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Sun Mar  3 03:14:19 2013 lysandre corjon
** Last update Sun Mar  3 03:24:35 2013 lysandre corjon
*/

#include <string.h>
#include <stdlib.h>
#include "grimly.h"

char	**tab_cpy(char **tab)
{
  int	i;
  int	size;
  char	**cpy;

  size = tab_len(tab);
  if ((cpy = malloc(++size * sizeof(*tab))) == NULL)
    {
      my_perror("Malloc Fail\n");
      return (NULL);
    }
  for (i = 0; i < size; i++)
    {
      if (tab[i] != NULL)
	{
	  if ((cpy[i] = strdup(tab[i])) == NULL)
	    {
	      my_perror("Not enough memory\n");
	      return (NULL);
	    }
	}
      else
	cpy[i] = NULL;
    }
  return (cpy);
}
