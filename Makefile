# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:22:15 by mpuig-ma          #+#    #+#              #
#    Updated: 2023/03/16 18:48:37 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHOR		?=	mpuig-ma
BUILD_DIR	:=	build
SRC_DIR		:=	src
NAME		:=	push_swap

CC			:=	gcc
CFLAGS		:=	-Wall -Werror -Wextra -O3
CCFLAGS		+=	-MMD
DEBUG		:=	-g -fsanitize='address,undefined' -Og
#CFLAGS		+=	$(DEBUG)
INC			:=	-I$(LIBFT_DIR)/src -I$(SRC_DIR)
RM			:=	rm -rf

OS			:=	$(shell uname)

NOSTYLE		:=	\033[0m
STYLE		:=	\033[0;32m

SRC_FILES	:=	src/arguments.c src/main.c src/push.c src/reverse_rotate.c \
				src/rotate.c src/stack.c src/swap.c
OBJ_FILES	=	$(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC_FILES)))))
DEP_FILES	=	$(addprefix $(BUILD_DIR)/, $(addsuffix .d, $(notdir $(basename $(SRC_FILES)))))

.PHONY: clean fclean re all #debug

$(NAME): $(OBJ_FILES) $(DEP_FILES) src/$(NAME).h
	$(CC) $(INC) $(CFLAGS) -O3 $(OBJ_FILES) -o $(basename $@)
	@echo "Built $(STYLE)$(basename $@)$(NOSTYLE)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(INC) $(CFLAGS) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)/

fclean: clean
	$(RM) $(NAME)*

re: fclean
	$(MAKE)

all: $(NAME)
