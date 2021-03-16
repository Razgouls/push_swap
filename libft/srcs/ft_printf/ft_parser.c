/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:34:46 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/26 09:47:06 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	ft_init_struct(void)
{
	t_format	f;
	int			i;

	i = -1;
	f.bool_syntax = -1;
	while (++i < 2)
		f.flags[i] = 0;
	f.check_star_width = 0;
	f.width = 0;
	f.check_star_precision = 0;
	f.precision = -1;
	f.type = 0;
	f.length = 0;
	return (f);
}

void		ft_flags_field(char const *s, t_format *f, int *i, int cmp)
{
	if (s[*i] != '0' && s[*i] != '-')
		return ;
	f->flags[cmp] = s[*i];
	(*i)++;
	while (s[*i])
	{
		if (s[*i] != '0' && s[*i] != '-')
			break ;
		if (s[*i] == '-')
			f->flags[cmp] = s[*i];
		(*i)++;
	}
}

void		ft_width_field(char const *s, t_format *f, int *i, va_list ap)
{
	if (s[*i] >= '0' && s[*i] <= '9')
	{
		if (f->flags[0] == 0)
			f->flags[0] = ' ';
		f->width = ft_atoi_new_str(s + (*i));
		(*i) += ft_strlen_number(f->width);
	}
	else if (s[*i] == '*')
	{
		if (f->flags[0] == 0)
			f->flags[0] = ' ';
		f->check_star_width = 1;
		f->width = (int)va_arg(ap, int);
		if (f->width <= -1)
		{
			f->flags[0] = '-';
			f->width *= -1;
		}
		(*i)++;
	}
}

void		ft_precision_field(char const *s, t_format *f, int *i, va_list ap)
{
	if (s[*i] != '.')
		return ;
	if (*i == 1)
		f->flags[0] = '0';
	(*i)++;
	if (s[*i] == '*')
	{
		f->check_star_precision = 1;
		f->precision = (int)va_arg(ap, int);
		(*i)++;
		return ;
	}
	if (s[*i] == 'c' || s[*i] == 's' || s[*i] == 'p' ||
		s[*i] == 'd' || s[*i] == 'i' ||
		s[*i] == 'u' || s[*i] == 'x' || s[*i] == 'X' || s[*i] == '%')
	{
		f->precision = 0;
		return ;
	}
	else
	{
		f->precision = ft_atoi_new_str(s + (*i));
		while (s[*i] >= '0' && s[*i] <= '9')
			(*i)++;
	}
}

void		ft_type_field(char const *s, t_format *f, int *i)
{
	if (s[*i] == 'c' || s[*i] == 's' || s[*i] == 'p' ||
		s[*i] == 'd' || s[*i] == 'i' ||
		s[*i] == 'u' || s[*i] == 'x' || s[*i] == 'X' || s[*i] == '%')
	{
		f->type = s[*i];
		f->bool_syntax = 0;
		(*i)++;
	}
}
