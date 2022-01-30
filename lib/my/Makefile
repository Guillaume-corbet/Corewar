##
## EPITECH PROJECT, 2018
## makefile
## File description:
## lib
##

SRC	=	$(shell find . -name '*.c')

OBJ     =	$(SRC:.c=.o)

NAME	=	libmy.a

NAMEM	=	my.h

ARG	=	*.c

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(ARG)
	ar rc $(NAME) $(OBJ)
	make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
