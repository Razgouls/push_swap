GREEN = \033[01;32m
YELLOW = \033[01;33m
CYAN = \033[01;36m
RESET = \033[00m
RED = \033[0;31m

NAME = checker

CC = clang 

FLAGS = -g3 -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INC= -I./includes

#############################################
######			FILES .C			#########
#############################################

SRC = srcs

DIR_C = $(addprefix $(SRC)/, checker)

FILES_C = $(addprefix $(SRC)/, $(BUILTINS))
BONUS_C = $(addprefix $(SRC)/, $(BUILTINS))

BUILTINS = $(addprefix checker/,	\
			ft_checker.c)

#OTHERS = ft_lst_history.c			

#############################################
######			FILES .O			#########
#############################################

OBJ_DIR = objs
O_DIR = $(DIR_C:$(SRC)/%=$(OBJ_DIR)/%)
OBJS = $(FILES_C:$(SRC)/%.c=$(OBJ_DIR)/%.o)

OBJS_BONUS = $(BONUS_C:$(SRC)/%.c=$(OBJ_DIR)/%.o)
#############################################
######			FILES .O			#########
#############################################

#@printf "$(YELLOW)Compiling Object...$(RESET) %33.33s        \r" "$@"

all: $(NAME)

$(LIBFT) :
	@echo "\n$(YELLOW)Compiling libft..."
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS) 
	@printf "$(YELLOW)Compiling Object...$(RESET)                                                       "
	@printf "\n$(GREEN)-->[OK]                       $(RESET)"
	@printf "\n$(CYAN)Compiling $@..."
	-@$(CC) $(FLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME) -ltermcap
	@echo "\n$(GREEN)-->[OK]$(RESET)"

$(OBJ_DIR)/%.o: $(SRC)/%.c
	@mkdir -p objs/ $(O_DIR)
	@printf "$(YELLOW)Compiling Object...$(RESET) %33.33s										\r" "$@"
	@$(CC) $(FLAGS) -o $@ -c $< $(INCL)

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS) 
	@printf "$(YELLOW)Compiling Object...$(RESET)                                                       "
	@printf "\n$(GREEN)-->[OK]                       $(RESET)"
	@printf "\n$(CYAN)Compiling $@..."
	-@$(CC) $(FLAGS) $(INC) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS) -ltermcap
	@echo "\n$(GREEN)-->[OK]$(RESET)"

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

.PHONY: all clean fclean re start