# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:22:15 by mpuig-ma          #+#    #+#              #
#    Updated: 2023/03/15 15:39:33 by mpuig-ma         ###   ########.fr        #
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
INC			:=	-I$(LIBFT_DIR) -I$(SRC_DIR)
RM			:=	rm -rf

OS			:=	$(shell uname)

NOSTYLE		:=	\033[0m
STYLE		:=	\033[0;32m

SRC_FILES	:=	main.c
SRC_FILES	:=	$(addpreffix $(SRC_DIR), $(SRC_FILES))
#OBJ_FILES	=	$()
#DEP_FILES	=	$()

.PHONY: clean fclean re all #debug

$(NAME): #$(LIBFT) $(OBJ_FILES) $(DEP_FILES) src/$(NAME).h
	$(CC) $(INC) $(CFLAGS) $(LFLAGS) -O3 $(SRC_FILES) -o $(basename $@)
	@echo "Builtt $(STYLE)$(basename $@)$(NOSTYLE)"

$(LIBFT):
	make -C $(dir $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(INC) $(CFLAGS) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)/ $(LIBFT)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)*

re: fclean
	$(MAKE)

all: $(NAME)
