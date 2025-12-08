NAME =	solong.a
PRGNAME = so_long
SRC	= 	flood_fill.c ft_putnbr.c ft_strlen.c get_next_line_utils.c get_next_line.c \
		is_valid.c main.c move.c set_image.c set_map.c

OBJ	=	$(SRC:.c=.o)


CC	= cc
CFLAGS	= -Wall -Werror -Wextra 
RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
		ar -rcs $(NAME) $(OBJ)
		cc $(CFLAGS) $(SRC) -lmlx -lX11 -lXext -lm  -o $(PRGNAME) $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY:			all clean fclean re