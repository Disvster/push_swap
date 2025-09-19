# LIBFT
LIBFTDIR = src/libft
LIBFTSRC =	ft_putendl_fd.c ft_isprint.c ft_strlcpy.c ft_atoi.c ft_lstclear_bonus.c \
			ft_strjoin.c ft_strrchr.c ft_isalpha.c ft_strlen.c ft_lstsize_bonus.c \
			ft_toupper.c ft_lstadd_back_bonus.c ft_strmapi.c ft_memcpy.c ft_lstdelone_bonus.c \
			ft_isdigit.c ft_putstr_fd.c ft_striteri.c ft_isalnum.c ft_memset.c \
			ft_itoa.c ft_split.c ft_calloc.c ft_strlcat.c ft_lstmap_bonus.c \
			ft_putnbr_fd.c ft_lstlast_bonus.c ft_memchr.c ft_strncmp.c \ 
			ft_lstadd_front_bonus.c \
			ft_bzero.c ft_memmove.c ft_substr.c ft_strtrim.c ft_lstnew_bonus.c \
			ft_strdup.c ft_lstiter_bonus.c ft_strchr.c ft_memcmp.c count_words.c \
			ft_strnstr.c ft_tolower.c ft_putchar_fd.c ft_isascii.c 
LIBFTSRCS = $(addprefix $(LIBFTDIR)/, $(LIBFTSRC))
LIBFTOBJS = $(addprefix $(OBJDIR)/, $(LIBFTSRC))

# GET NEXT LINE
GNLDIR = src/gnl
GNLSRC = get_next_line_bonus.c get_next_line_utils_bonus.c
GNLSRCS = $(addprefix $(GNLDIR)/, $(GNLSRC))
GNLOBJS = $(addprefix $(OBJDIR)/, $(GNLSRC))

# FT_PRINTF
PRINTFDIR = src/ft_printf
PRINTFSRC =	ft_printf.c ft_itoa_base.c ft_flags.c ft_itoa_pf.c ft_sub_cpy.c \
			ft_flags_helper2.c ft_see_format.c ft_indent.c ft_itoa_pt.c \
			ft_printf_utils2.c ft_flags_helper.c ft_printf_utils.c
PRINTFSRCS =$(addprefix $(PRINTFDIR)/, $(PRINTFSRC))
PRINTFOBJS = $(addprefix $(OBJDIR)/, $(PRINTFSRC))

OBJDIR = obj
INCSDIR = incs/
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
AR = ar rcs
RM = rm -f

all: $(NAME)

$(LIBFTDIR)/%.o: $(LIBFTDIR)/%.c
	$(CC) $(FLAGS) -c $< -o $(OBJDIR)/$@ -I $(INCSDIR)

$(PRINTFDIR)/%.o: $(PRINTFDIR)/%.c
	$(CC) $(FLAGS) -c $< -o $(OBJDIR)/$@ -I $(INCSDIR)

$(GNLDIR)/%.o: $(GNLDIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(ARRCS) $(NAME) $(OBJS_DIR)/$(OBJ)

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
