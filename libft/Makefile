# compile:
# 	$(CC) $(CFLAGS) *srcs/*.c -I incs/
# 	mv *.o $(OBJS_DIR)/

# FNAMES = find -type f -wholename '*srcs/*.c' -exec basename -s '.c' {} \; | tr '\n' ' '
# SRCS = find -type f -wholename '*srcs/*.c' | tr '\n' ' '
# OBJS = find -type f -wholename '*srcs/*.o' | tr '\n' ' '
# OBJ := $(patsubst src/%.c,obsj/%.o,$(SRC))
SRC := $(shell find src -type f -name '*.c')
OBJ := $(addsuffix .o,$(notdir $(basename $(SRC))))
SRC_DIR = src
OBJ_DIR = obj
CC = cc
CFLAGS = -Wall -Werror -Wextra -c
NAME = libft.a
AR = ar rcs
RM = rm -f

%.o: $(SRC)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

$(NAME): $(OBJ)
	$(ARRCS) $(NAME) $(OBJS_DIR)/$(OBJ)

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
