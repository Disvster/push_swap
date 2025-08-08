# FNAMES = find -type f -wholename '*srcs/*.c' -exec basename -s '.c' {} \; | tr '\n' ' '
SRCS = find -type f -wholename '*srcs/*.c' | tr '\n' ' '
OBJS = find -type f -wholename '*srcs/*.o' | tr '\n' ' '
OBJS_DIR = ./objs
CC = cc
CFLAGS = -Wall -Werror -Wextra -c
NAME = libft.a
ARRCS = ar rcs
# ARRS = ar rs
RM = rm -f

# fnames:
# 	find -type f -wholename '*srcs/*.c' -exec basename -s '.c' {} \; | tr '\n' ' '

compile:
	$(CC) $(CFLAGS) *srcs/*.c -I incs/
	mv *.o $(OBJS_DIR)/

$(NAME): compile
	$(ARRCS) $(NAME) $(OBJS_DIR)/*.o

all: $(NAME)
	
clean:
	$(RM) $(OBJS_DIR)/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
# vou fazer este Makefile que vai correr make de cada projeto
# mandar os ficheiros .o para uma pasta e arquivar tudo num ficheiro .a
# que vai ficar na root da dir libft/
# pode pegar em tudo o que seja "*srcs/" compilar esses ficheiros com
# '-I ../incs/ e mandar tudo para libft/objs
# depois 'ar rca libft.a objs/*.o'
#
# talvez nao tenha que usar os makefiles de cada branch(projeto) da lib
