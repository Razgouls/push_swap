/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_affichage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:11:15 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/02 14:00:35 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_types_field(va_list p, t_format *f)
{
	char	c;

	c = f->type;
	if (c == 'd' || c == 'i')
		ft_d(f, (int)va_arg(p, int));
	else if (c == 'u')
		ft_u(f, (unsigned int)va_arg(p, unsigned int));
	else if (c == 'x' || c == 'X')
		ft_hexa(f, (unsigned int)va_arg(p, unsigned int), c);
	else if (c == '%')
		ft_percent(f, c);
	else if (c == 'c')
		ft_percent(f, (char)va_arg(p, int));
	else if (c == 's')
		ft_str(f, (char *)va_arg(p, unsigned char *));
	else if (c == 'p')
		ft_p(f, (unsigned long long)va_arg(p, void *));
	va_end(p);
	return (0);
}

void	ft_str(t_format *f, char *str)
{
	int tmp;
	int check;

	check = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		check = 1;
	}
	tmp = ft_strlen(str);
	ft_str_aux(f, str, tmp);
	if (check)
		free(str);
}

void	ft_str_aux(t_format *f, char *str, int tmp)
{
	if (f->precision < (int)ft_strlen(str) && f->precision >= 0)
		tmp = f->precision;
	if (f->precision >= 0
			&& f->width > 0 && f->flags[0] != '-')
		f->length += ft_print_str_bis(' ',
			f->width - tmp, f->precision, str);
	else if (f->flags[0] == '0' && f->width > 0)
		f->length += ft_print_str_bis('0',
			f->width - ft_strlen(str), tmp, str);
	else if (f->flags[0] == '-' && f->width > 0)
		f->length += ft_print_str(' ', f->width, tmp, str);
	else if (f->precision >= 0)
		f->length += ft_print_str(' ', 0, f->precision, str);
	else if (f->width > 0)
		f->length += ft_print_str_bis(' ',
			f->width - ft_strlen(str), ft_strlen(str), str);
	else
		f->length += ft_print_str(' ', 0, ft_strlen(str), str);
}
