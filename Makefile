##
## Makefile for grimly in /home/corjon_l//rush
## 
## Made by lysandre corjon
## Login   <corjon_l@epitech.net>
## 
## Started on  Fri Mar  1 20:43:06 2013 lysandre corjon
## Last update Sat Mar  2 23:06:31 2013 lysandre corjon
##


CC	=	gcc

RM	=	rm -f

CFLAGS	=	-g -g3 -Wall -Wextra

NAME	=	grimly

SRC	=	grimly.c \
		check_file.c \
		info.c \
		get_next_line.c \
		tools.c \
		my_perror.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re