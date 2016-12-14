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

N_S				= static

N_D				= dynamic

N_I				= interactive

CC 				= gcc

RM 				= rm -f

SRCS 			= exiasaver.c \
					getTime.c
                  
STAT 			= static.c

DYNA 			= dynamic.c

INTER			= interactive.c

OBJ 			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ)
		$(CC) -o $(N_S) static.c
		$(CC) -o $(N_D) dynamic.c
		$(CC) -o $(N_I) interactive.c
		$(RM) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME) $(N_S) $(N_D) $(N_I)

re: fclean all

.PHONY: fclean clean all re