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

# PROGRESS BAR
TOTAL_C := $(shell find src/ -type f -name '*.c' -not -path '*/.*' | wc -l)

define	progress_bar
	@COUNT=$$(find obj -type f -name '*.o' | wc -l); \
	BAR_WIDTH=30; \
	NUM_HASHES=$$(( COUNT * BAR_WIDTH / $(TOTAL_C) )); \
	BAR=$$(printf "%-$${BAR_WIDTH}s" "$$(printf '%0.s#' $$(seq 1 $$NUM_HASHES))"); \
	echo -ne "Compiling: [$$BAR] ($$COUNT/$(TOTAL_C))\r"
endef


INCS_DIR = incs/
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = push_swap
RM = rm -f

all: $(OBJ_DIR) $(LIB) $(NAME)
	@echo -e "Compilation complete! push_swap file generated.        \n"

print_ps:
	@echo -e "\n===  Push_Swap  ==="

libft:
	@echo "=====  Libft  ====="
	@make --no-print-directory -C $(LIB_DIR)

$(OBJ_DIR):
	@mkdir $@

$(LIB):
	@echo "=====  Libft  ====="
	@make --no-print-directory -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(MOV_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)
	$(progress_bar)

$(OBJ_DIR)%.o: $(OPS_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)
	$(progress_bar)

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)
	$(progress_bar)

$(NAME): print_ps $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

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

.PHONY: all clean fclean re libft print_ps
# # TESTING
# TEST_PS = test_ps
# TEST_DIR = src/db/
# TEST_SRC = src/db/print_stack.c src/db/main.c
#
# $(TEST_PS): print_ps $(OBJ) $(LIB)
# 	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(TEST_PS)
