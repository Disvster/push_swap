# compile:
# 	$(CC) $(CFLAGS) *srcs/*.c -I incs/
# 	mv *.o $(OBJS_DIR)/

# FNAMES = find -type f -wholename '*srcs/*.c' -exec basename -s '.c' {} \; | tr '\n' ' '
# SRCS = find -type f -wholename '*srcs/*.c' | tr '\n' ' '
# OBJS = find -type f -wholename '*srcs/*.o' | tr '\n' ' '
# OBJ := $(patsubst src/%.c,obsj/%.o,$(SRC))
SRC := $(shell find src -type f -name '*.c' | tr '\n' ' ')
OBJ := $(addsuffix .o,$(notdir $(basename $(SRC))))
SRC_DIR = src
OBJ_DIR = obj
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
AR = ar rcs
RM = rm -f

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

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
#
# CC      = cc
# CFLAGS  = -Wall -Werror -Wextra
#
# SRC_DIR = src
# OBJ_DIR = obj
#
# SRC = \
# 	$(SRC_DIR)/ft_putendl_fd.c \
# 	$(SRC_DIR)/ft_isprint.c \
# 	$(SRC_DIR)/ft_strlcpy.c \
# 	$(SRC_DIR)/ft_atoi.c \
# 	$(SRC_DIR)/ft_lstclear_bonus.c \
# 	$(SRC_DIR)/ft_strjoin.c \
# 	$(SRC_DIR)/ft_split.c \
# 	$(SRC_DIR)/ft_lstmap_bonus.c \
# 	$(SRC_DIR)/ft_memchr.c \
# 	$(SRC_DIR)/ft_memcmp.c \
# 	$(SRC_DIR)/ft_strnstr.c \
# 	$(SRC_DIR)/ft_strchr.c \
# 	$(SRC_DIR)/count_words.c \
# 	$(SRC_DIR)/ft_lstnew_bonus.c \
# 	$(SRC_DIR)/ft_strdup.c \
# 	$(SRC_DIR)/ft_lstiter_bonus.c \
# 	$(SRC_DIR)/ft_calloc.c \
# 	$(SRC_DIR)/ft_strlcat.c \
# 	$(SRC_DIR)/ft_putnbr_fd.c \
# 	$(SRC_DIR)/ft_lstlast_bonus.c \
# 	$(SRC_DIR)/ft_strncmp.c \
# 	$(SRC_DIR)/ft_isascii.c \
# 	$(SRC_DIR)/ft_lstadd_front_bonus.c \
# 	$(SRC_DIR)/ft_tolower.c \
# 	$(SRC_DIR)/ft_bzero.c \
# 	$(SRC_DIR)/ft_strrchr.c \
# 	$(SRC_DIR)/ft_putchar_fd.c \
# 	$(SRC_DIR)/ft_memmove.c \
# 	$(SRC_DIR)/ft_isalpha.c \
# 	$(SRC_DIR)/ft_substr.c \
# 	$(SRC_DIR)/ft_strtrim.c \
# 	$(SRC_DIR)/ft_strlen.c \
# 	$(SRC_DIR)/ft_isalnum.c \
# 	$(SRC_DIR)/ft_memcpy.c \
# 	$(SRC_DIR)/ft_lstsize_bonus.c \
# 	$(SRC_DIR)/ft_memset.c \
# 	$(SRC_DIR)/ft_toupper.c \
# 	$(SRC_DIR)/ft_lstdelone_bonus.c \
# 	$(SRC_DIR)/ft_itoa.c \
# 	$(SRC_DIR)/ft_isdigit.c \
# 	$(SRC_DIR)/ft_striteri.c \
# 	$(SRC_DIR)/ft_putstr_fd.c \
# 	$(SRC_DIR)/ft_strmapi.c \
# 	$(SRC_DIR)/ft_lstadd_back_bonus.c
#
# OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
#
# all: $(OBJ_DIR) $(OBJ)
#
# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)
#
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@
#
# clean:
# 	rm -rf $(OBJ_DIR)
