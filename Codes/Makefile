
NAME =		eXiaSaver

CC	 = 		gcc

RM	 = 		rm -f

SRCS = 		*.c 

OBJ  = 		$(SRCS:.c=.o)

all:(NAME)
	$(CC) -o $(NAME) $(OBJ)

clean: $(OBJ)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all re
