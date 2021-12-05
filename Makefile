CFILES = ft_printf.c ft_putstr.c ft_strlen.c ft_auxil.c
OFILES = ft_printf.o ft_putstr.o ft_strlen.o ft_auxil.o
BC = ft_atoi.c ft_putstr.c ft_strlen.c ft_auxil.c ft_printf_bonus.c ft_bonus_utils.c
BO = ft_atoi.o ft_putstr.o ft_strlen.o ft_auxil.o ft_printf_bonus.o ft_bonus_utils.o
CC = gcc
LIB = ft_printf.h
W = -c -Wall -Werror -Wextra
NAME = libftprintf.a
${NAME} : ${OFILES} ${LIB}
%.o : %.c $(LIB)
	$(CC) $(W) $< -o $@
	ar -cr ${NAME} $@
bonus : ${BO} ${LIB}
	@${CC} ${W} ${BC}
	@ar -cr ${NAME} ${BO}
clean :
	@rm -f ${OFILES} ${BO}
fclean : clean
	@rm -f ${NAME}
re : fclean all
all : ${NAME}
.PHONY:	 clean all fclean re
