# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 17:06:16 by gozsertt          #+#    #+#              #
#    Updated: 2021/09/07 06:34:39 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   philo

CC          =   gcc

SRC_DIR		= 	$(shell find srcs -type d)
INC_DIR		= 	$(shell find includes -type d)
OBJ_DIR		=	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

SRC			= 	philo.c										\
				philo_t_state_constructor_destructor.c		\
				philo_t_state_getter.c						\
				philo_t_state_setter.c						\
				philo_t_time_constructor_destructor.c		\
				philo_t_time_getter.c						\
				philo_t_time_setter.c						\
				philo_t_philo_getter.c						\
				philo_t_philo_address_getter.c				\
				philo_t_philo_constructor_destructor.c		\
				philo_t_philo_setter.c						\
				philo_utils.c								\
				philo_action.c								\
				philo_start_philosopher.c					\
				philo_parsing.c								\

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags

CFLAGS      =	-Wall -Wextra -Werror -pthread

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

# Colors

_GREY=	$'\e[30m
_RED=	$'\e[31m
_GREEN=	$'\e[32m
_YELLOW=$'\e[33m
_BLUE=	$'\e[34m
_PURPLE=$'\e[35m
_CYAN=	$'\e[36m
_WHITE=	$'\e[37m

# MAIN part --------------------------------------------------------

all:
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make $(NAME)

show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) -o $(NAME)$(_WHITE)"

$(NAME): $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

re:	fclean all

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all show re clean flcean