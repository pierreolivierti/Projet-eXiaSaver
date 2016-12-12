##
## Makefile for eXiaServer in /Users/MacBook/Desktop/Projet eXiaSaver/Projet-eXiaSaver/Codes
## 
## Made by 
## Login	 <-Pierre-Olivier TILLOY->
## 
## Started on	Wed Dec	7 15:14:34 2016 
## Last update	Wed Dec	7 15:14:34 2016 
##

NAME 			= eXiaSaver

CC 				= gcc

RM 				= rm -f

SRCS 			= exiasaver.c\
                  
OBJ 			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all re