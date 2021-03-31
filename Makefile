NAME			= checker

SRCS_LIST 		= checker/ft_checker.c				\
					checker/ft_fill_stack.c			\
					utils/ft_debug.c				\
					utils/ft_list.c					\
					utils/ft_utils.c				\
					operandes/ft_operande_a.c		\
					operandes/ft_operande_b.c		\
					operandes/ft_operande_s.c		\
					operandes/ft_operande_spec.c	\
					push_swap/ft_insertion.c		\
					push_swap/ft_radix_sort.c		\
					push_swap/ft_small_len.c		\
					push_swap/ft_med_len.c			\

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs
LIBFT 			= libft

CC				= clang
CFLAGS 			= -Wall -Wextra -Werror
LFLAGS			= -L libft -lft

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "-----> COMPILATION LIBFT <-----"
				@make -C $(LIBFT)
				@${CC} $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c
				-@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
				@echo "[OK] : $<"

clean:
				@echo "-----> CLEAR OK <-----"
				@$(RM) $(OBJS)

fclean:			clean
				@echo "-----> COMPILATION FCLEAN OK <-----"
				@$(RM) $(NAME)
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re