NAME			= checker

SRCS_LIST 		= checker/ft_checker.c				\
					checker/ft_fill_stack.c			\
					utils/ft_debug.c				\
					utils/ft_list.c					\
					utils/ft_utils.c				\
					operandes/ft_operande_a.c		\
					operandes/ft_operande_b.c		\
					operandes/ft_operande_s.c		\

GREEN   		= \e[32m
RESET   		= \e[39m

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs
LIBFT 			= libft

CC				= clang
CFLAGS 			= -Wall -Wextra -Werror
LFLAGS			= -L libft -lft
MLX_DIR			= minilibx-linux

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "$(GREEN) -----> COMPILATION LIBFT <----- $(RESET)"
				@make -C $(LIBFT)
				@${CC} $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c
				-@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
				@echo "$(GREEN) [OK] : $(RESET) $<"

clean:
				@echo "$(GREEN) -----> CLEAR OK <----- $(RESET)"
				@$(RM) $(OBJS)

fclean:			clean
				@echo "$(GREEN) -----> COMPILATION FCLEAN OK <----- $(RESET)"
				@$(RM) $(NAME)
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re