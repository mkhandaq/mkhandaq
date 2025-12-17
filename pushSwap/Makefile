NAME =	ftpushswap.a
PRGNAME = push_swap
SRC	=	checker.c ft_atoi.c ft_lstsize_bonus.c hardCodded.c helpingf.c indexing.c \
 		main.c pop.c pushpop.c radix.c rop.c rrop.c sop.c

OBJ	=	$(SRC:.c=.o)


CC	= cc
CFLAGS	= -Wall -Werror -Wextra
RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
		ar -rcs $(NAME) $(OBJ)
		cc $(CFLAGS) $(SRC) -o $(PRGNAME) $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY:			all clean fclean re