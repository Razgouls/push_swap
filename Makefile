# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/31 18:07:16 by eoliveir          #+#    #+#              #
#    Updated: 2021/03/31 18:15:29 by eoliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[01;32m
YELLOW = \033[01;33m
CYAN = \033[01;36m
RESET = \033[00m
RED = \033[0;31m

NAME = push_swap

CHECKER_NAME = checker

CC = clang 

FLAGS = -g3 -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INC= -I./includes

#############################################
######			FILES .C			#########
#############################################

SRC = srcs

DIR_C = $(addprefix $(SRC)/, checker operandes push_swap utils)

FILES_C = $(addprefix $(SRC)/, $(CHECKER) $(PUSH_SWAP) $(OPERANDES) $(UTILS))

FILES_CHECKER = $(addprefix $(SRC)/, $(CHECKER) $(PUSH_SWAP) $(OPERANDES) $(UTILS))

CHECKER		= $(addprefix checker/,			\
			ft_checker.c					\
			ft_fill_stack.c					\
			)

PUSH_SWAP	= $(addprefix push_swap/,		\
			ft_insertion.c					\
			ft_small_len.c					\
			)
			
OPERANDES	= $(addprefix operandes/,		\
			ft_operande_a.c					\
			ft_operande_b.c					\
			ft_operande_s.c					\
			)
UTILS		= $(addprefix utils/,		\
			ft_debug.c						\
			ft_list.c						\
			ft_utils.c						\
			)	

#############################################
######			FILES .O			#########
#############################################

OBJ_DIR = objs
O_DIR = $(DIR_C:$(SRC)/%=$(OBJ_DIR)/%)
OBJS = $(FILES_C:$(SRC)/%.c=$(OBJ_DIR)/%.o)

CHECKER_OBJS = $(FILES_CHECKER:$(SRC)/%.c=$(OBJ_DIR)/%.o)
#############################################
######			FILES .O			#########
#############################################

#@printf "$(YELLOW)Compiling Object...$(RESET) %33.33s        \r" "$@"

all: $(NAME) $(CHECKER_NAME)

$(LIBFT) :
	@echo "\n$(YELLOW)Compiling libft..."
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS) 
	@printf "$(YELLOW)Compiling Object...$(RESET)                                                       "
	@printf "\n$(GREEN)-->[OK]                       $(RESET)"
	@printf "\n$(CYAN)Compiling $@..."
	-@$(CC) $(FLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME) -ltermcap
	@echo "\n$(GREEN)-->[OK]$(RESET)"

$(CHECKER_NAME): $(CHECKER_OBJS)
	@printf "$(YELLOW)Compiling Object...$(RESET)                                                       "
	@printf "\n$(GREEN)-->[OK]                       $(RESET)"
	@printf "\n$(CYAN)Compiling $@..."
	-@$(CC) $(FLAGS) $(INC) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER_NAME) -ltermcap
	@echo "\n$(GREEN)-->[OK]$(RESET)"

$(OBJ_DIR)/%.o: $(SRC)/%.c
	@mkdir -p objs/ $(O_DIR)
	@printf "$(YELLOW)Compiling Object...$(RESET) %33.33s										\r" "$@"
	@$(CC) $(FLAGS) -o $@ -c $< $(INCL)

clean:
	@echo " $(RED)__Clean__"
	@echo "$(RESET)|  libft  |"
	make -s clean -C ./libft
	@echo "|  OBJS   |"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)__Cleaned__$(RESET)"

fclean: clean
	@make -s fclean -C ./libft
	@echo
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(RED)$(NAME) removed$(RESET)"
	@echo "------------------------------"

re: fclean all

.SILENT: clean

.PHONY: all clean fclean re