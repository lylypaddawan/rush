/*
** grimly.h for grimly in /home/corjon_l//rush/rush
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Fri Mar  1 22:43:09 2013 lysandre corjon
** Last update Sat Mar  2 23:06:08 2013 lysandre corjon
*/

#ifndef GRIMLY_H_
# define GRIMLY_H_

# define	READ_LEN	(35)
# define	ENTRY		(10)
# define	EXIT		(20)

typedef struct	s_way
{
  void		*data;
  int		type;
  int		cur_x;
  int		cur_y;
  struct s_way	*next;
}		t_way;

typedef struct	s_pt
{
  int		type;
  int		x;
  int		y;
  t_way		*way;
  struct s_pt	*next;
}		t_pt;

typedef struct	s_info
{
  int		width;
  int		heigth;
  t_pt		*point;
}		t_info;

typedef struct	s_ll
{
  void		*data;
  struct s_ll	*next;
}		t_ll;

int	get_entry(t_info **info, char **tab);
int	get_info(t_info **info, char **tab);
char    **put_ll_to_tab(t_info **info, int count, char **tab, t_ll *list);
int	is_file(char *str);
int	tab_len(char **tab);
void	free_list(t_ll *list);
t_info	**get_tall(char *str, t_info **info);
t_ll	*feel_ll(t_ll *file, char *str);
char	**get_file_in_tab(int fd, t_info **info);
char	**check_file(char *str, t_info **info);
int	mem_ret(char *ret[1], char *save, char *tmp, int ret_len);
int	add_save(char *ret[1], char *save);
void	evolve_save(char *save);
char	*get_next_line(const int fd);
int	check_name(char *name);
int	main(int ac, char **av);
void	my_perror(char *str);

#endif /* !GRIMLY_H_ */
