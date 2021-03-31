# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 09:04:13 by eoliveir          #+#    #+#              #
#    Updated: 2021/03/30 07:18:30 by eoliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS_LIST	= 	ft_atoi.c \
				ft_bzero.c \
				ft_isalpha.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strchr.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_split_multi.c \
				ft_sqrt.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_get_next_line.c \
				ft_strlen_number.c \
				ft_strdel.c \
				ft_strndup.c \
				ft_strcmp.c \
				ft_atof.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_strcat.c \
				ft_reverse_tab.c \
				ft_len_new_base.c \
				ft_atoi_base.c \
				ft_convert_base.c \
				ft_clamp.c \
				ft_calc_determinant.c \
				ft_abs.c \
				ft_rad_to_deg.c \

SRCS		= $(addprefix ${FOLDER}/, ${SRCS_LIST})
OBJS		= ${SRCS:.c=.o}

HEADER		= includes
FOLDER		= srcs

FT_PRINTF 	= $(FOLDER)/ft_printf

CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror
RM			= rm -f

$(NAME):	${OBJS}
			@echo "-----> COMPILATION FT_PRINTF <-----"
			@make -C $(FT_PRINTF)
			@cp $(FT_PRINTF)/libftprintf.a ./$(NAME)
			@ar -rcs ${NAME} ${OBJS}

%.o: %.c
			@${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}
			@echo "[OK] : $<"

all:		${NAME}

clean:
			@${RM} ${OBJS}
			@make clean -C $(FT_PRINTF)

fclean:		clean
			@${RM} ${NAME}
			@make fclean -C $(FT_PRINTF)

re:			fclean all

.PHONY: 	all fclean clean re