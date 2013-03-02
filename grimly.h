/*
** grimly.h for grimly in /home/corjon_l//rush/rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Fri Mar  1 22:43:09 2013 lysandre corjon
** Last update Sat Mar  2 02:40:34 2013 lysandre corjon
*/

#ifndef GRIMLY_H_
# define GRIMLY_H_

# define	READ_LEN	(35)

typedef struct	s_info
{
  int		width;
  int		height;
}		t_info;

typedef struct	s_ll
{
  void		*data;
  struct s_ll	*next;
}		t_ll;

#endif /* !GRIMLY_H_ */
