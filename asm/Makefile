##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## for corewar
##

NAMEF	=	src/*.c \
			op.c

NAME	=	asm

OPT		=	-g3 -o

CFLAGS	=	-Werror -Wextra -W

LIB		=	-L ./../lib/my -lmy

$(NAME):	fclean
	(cd ../lib/my && make re -s)
	gcc $(OPT) $(NAME) $(NAMEF) $(LIB) $(CFLAGS)

all:	$(NAME)

clean:
	rm -f $(NAME)~

fclean: clean
	rm -f $(NAME)
	rm -f ../lib/my/libmy.a

re:	fclean all

auteur:
	echo $(USER) > auteur
