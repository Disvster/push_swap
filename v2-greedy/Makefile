SHELL :=/bin/bash

# PUSH_SWAP
MOV_DIR =	src/movements/
SRC_MOV =	src/movements/rotations.c \
			src/movements/pushes.c \
			src/movements/swaps.c
OPS_DIR =	src/ops/
SRC_OPS =	src/ops/rot_handler.c \
			src/ops/find.c \
			src/ops/small_sort.c \
			src/ops/ops/big_sort.c \
			src/ops/main.c
UTILS_DIR =	src/utils/
SRC_UTILS =	src/utils/tab_utils.c \
			src/utils/stack.c \
			src/utils/utils.c
SRCS = $(SRC_MOV) $(SRC_OPS) $(SRC_UTILS)

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR),$(notdir $(SRCS:.c=.o)))

# LIBFT
LIB = ../libft/libft.a
LIB_DIR = ../libft/

INCS_DIR = incs/
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
RM = rm -f

all: $(OBJ_DIR) $(LIB) $(NAME)
	@echo -e "Compilation complete! push_swap file generated.        "

$(OBJ_DIR):
	@mkdir $@

$(LIB):
	@echo "=====  Libft  ====="
	@make --no-print-directory -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(MOV_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

$(OBJ_DIR)%.o: $(OPS_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

clean: $(OBJ_DIR)
	@echo -e "\n=====  Libft  ====="
	@make --no-print-directory -C $(LIB_DIR) clean
	@echo -e "\n===  Push_Swap  ==="
	@$(RM) -r $(OBJ_DIR)
	@echo -e "cleaned .o files\n"

fclean: $(OBJ_DIR)
	@echo -e "\n=====  Libft  ====="
	@make --no-print-directory -C $(LIB_DIR) fclean
	@echo -e "\n===  Push_Swap  ==="
	@$(RM) -r $(OBJ_DIR)
	@echo "Cleaned .o files"
	@$(RM) $(NAME)
	@echo -e "Cleaned push_swap executable\n"

re: fclean $(OBJ_DIR)
	@make --no-print-directory all

.PHONY: all clean fclean re
