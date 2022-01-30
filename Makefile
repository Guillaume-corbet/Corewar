##
## EPITECH PROJECT, 2019
## CPE_corewar_2018
## File description:
## Makefile
##

all:	
	(cd asm && make -s)

re:
	(cd asm && make re -s)

clean:
	(cd asm && make clean)

fclean:
	(cd asm && make fclean)
