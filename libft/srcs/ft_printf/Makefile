# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 09:04:13 by eoliveir          #+#    #+#              #
#    Updated: 2021/02/01 14:12:46 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS			=	ft_convert_hexa.c \
					ft_parser.c \
					ft_printf.c \
					ft_printf_affichage.c \
					ft_printf_affichage_bis.c \
					ft_printf_d.c \
					ft_printf_u.c \
					ft_printf_p.c \
					ft_printf_hexa.c \
					ft_printf_utils.c \
					ft_printf_c.c

OBJS			= ${SRCS:.c=.o}

HEADER			= ../../includes

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@ar -rcs ${NAME} ${OBJS}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<
				@echo "[OK] : $<"

clean:
				@${RM} ${OBJS}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all

.PHONY: 		all fclean clean re