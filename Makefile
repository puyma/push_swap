# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:22:15 by mpuig-ma          #+#    #+#              #
#    Updated: 2023/04/02 18:12:44 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHOR		?=	mpuig-ma
BUILD_DIR	:=	build
SRC_DIR		:=	src
LIBFT_DIR	:=	$(SRC_DIR)/libft
LIBFT		:=	$(LIBFT_DIR)/libft.a
NAME		:=	push_swap

CC			:=	gcc
CFLAGS		:=	-Wall -Werror -Wextra -O3
CCFLAGS		+=	-MMD
LFLAGS		:=	-L$(LIBFT_DIR) -lft
DEBUG		:=	-g -fsanitize='address,undefined' -Og
#CFLAGS		+=	$(DEBUG)
INC			:=	-I$(LIBFT_DIR)/src -I$(SRC_DIR)
RM			:=	rm -rf

OS			:=	$(shell uname)

NOSTYLE		:=	\033[0m
STYLE		:=	\033[0;32m

SRC_FILES	:=	src/arguments.c \
				src/ft_issorted.c \
				src/lists_a.c \
				src/lists_b.c \
				src/logic_chunks.c \
				src/logic_mini.c \
				src/main.c \
				src/operations.c \
				src/utils.c
OBJ_FILES	=	$(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC_FILES)))))
DEP_FILES	=	$(addprefix $(BUILD_DIR)/, $(addsuffix .d, $(notdir $(basename $(SRC_FILES)))))

BONUS_FILES	:=	src/arguments.c \
				src/ft_issorted.c \
				src/lists_a.c \
				src/lists_b.c \
				src/logic_bonus.c \
				src/main_bonus.c \
				src/operation.c \
				src/utils.c
B_OBJ_FILES	=	$(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(notdir $(basename $(BONUS_FILES)))))
B_DEP_FILES	=	$(addprefix $(BUILD_DIR)/, $(addsuffix .d, $(notdir $(basename $(BONUS_FILES)))))

.PHONY: clean fclean re all debug bonus

$(NAME): $(LIBFT) $(OBJ_FILES) $(DEP_FILES) src/$(NAME).h
	$(CC) $(INC) $(CFLAGS) $(LFLAGS) -O3 $(OBJ_FILES) -o $(basename $@)
	@echo "Built $(STYLE)$(basename $@)$(NOSTYLE)"

checker: $(LIBFT) $(B_OBJ_FILES) $(B_DEP_FILES) src/$(NAME).h
	$(CC) $(INC) $(CFLAGS) $(LFLAGS) -O3 $(B_OBJ_FILES) -o $(basename $@)
	@echo "Built $(STYLE)$(basename $@)$(NOSTYLE)"

bonus: checker

$(LIBFT):
	make -C $(dir $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(INC) $(CFLAGS) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)/
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) checker

re: fclean
	$(MAKE)

all: $(NAME)
