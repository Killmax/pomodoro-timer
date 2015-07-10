##
## Makefile for pomodoro timer v1 in /home/brugue_m/Perso/projets_divers/pomodoro_c/V1
## 
## Made by Maxime B. (website : maxime-brgt.me)
## 
## Started on Fri Jul 10 12:35:25 2015 Maxime B.
## Last update Fri Jul 10 14:30:46 2015 Maxime B.
##

CC	=	gcc

CFLAGS	+=	-Wall -Wextra -I./include/

NAME	=	pomodoro-timer

SRC	=	src/pomodoro.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
		@echo "\033[1mCompilation done ! Check the header in ./include to modify parameters !\033[0m"

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all