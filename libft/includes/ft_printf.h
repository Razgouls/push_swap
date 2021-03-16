/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:13:04 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/31 16:54:27 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_f
{
	char			flags[2];
	int				check_star_width;
	int				width;
	int				check_star_precision;
	int				precision;
	int				bool_syntax;
	int				length;
	char			type;
}					t_format;

t_format			ft_init_struct(void);
void				ft_flags_field(char const *s,
						t_format *f, int *index, int cmp);
void				ft_width_field(char const *s,
						t_format *f, int *index, va_list ap);
void				ft_precision_field(char const *s,
						t_format *f, int *index, va_list ap);
void				ft_type_field(char const *s, t_format *f, int *index);
void				ft_convert_hexa(unsigned long long nb, char c);
int					ft_write_s_z(char c, int n);
void				ft_p(t_format *f, unsigned long long number);
int					ft_print_char(char c, int n, int number, int ordre);
int					ft_print_percent(char c, int n, char number, int ordre);
void				ft_print_number(int n);
int					ft_print_str(char c, int width, int precision, char *str);
int					ft_print_str_bis(char c, int width,
						int precision, char *str);
void				ft_d(t_format *f, int n);
void				ft_u(t_format *f, unsigned int n);
void				ft_percent(t_format *f, char c);
void				ft_str(t_format *f, char *str);
int					ft_atoi_new_str(char const *s);
int					ft_printf(const char *s, ...);
int					ft_strlen_number(int n);
int					ft_lennumber_u(unsigned int n);
void				ft_convert_hexa(unsigned long long n, char hexa);
int					ft_print_types_field(va_list ap, t_format *f);
int					ft_printf_aux(const char *s, int i,
							va_list ap, int *length);
int					ft_convert_hexa_len(unsigned long long nb);
void				ft_putnbr_fd_u(unsigned int n, int fd);
void				ft_print_d_left(t_format *f, int n, char c, int length);
void				ft_print_d_right(t_format *f, int n, char c, int length);
void				ft_print_u_left(t_format *f, unsigned int n, char c);
void				ft_print_u_right(t_format *f, unsigned int n, char c);
void				ft_print_hexa_left(t_format *f,
						long long n, char c, char hexa);
void				ft_print_hexa_right(t_format *f,
						long long n, char c, char hexa);
void				ft_print_p_left(t_format *f, unsigned long long n, char c);
void				ft_print_p_right(t_format *f, unsigned long long n, char c);
void				ft_hexa(t_format *f, unsigned int n, char hexa);
void				ft_print_percent_left(t_format *f, char p_c, char c);
void				ft_print_percent_right(t_format *f, char p_c, char c);
void				ft_str_aux(t_format *f, char *str, int tmp);
void				ft_print_hexa_left_aux(t_format *f,
						long long n, char hexa, char c);
void				ft_print_d_left_aux(t_format *f, int n, char c, int length);

#endif
