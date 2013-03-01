##
## Makefile for grimly in /home/corjon_l//rush
## 
## Made by lysandre corjon
## Login   <corjon_l@epitech.net>
## 
## Started on  Fri Mar  1 20:43:06 2013 lysandre corjon
## Last update Fri Mar  1 20:43:42 2013 lysandre corjon
##


CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra

NAME	= mysh

SRC	=

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re