/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_affichage_bis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:49:53 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/02 14:07:58 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_d(t_format *f, int n)
{
	int	length_n;

	length_n = ft_strlen_number(n);
	if (f->precision == 0 && n == 0)
		f->length += ft_write_s_z(' ', f->width);
	else if (f->flags[0] == '0' && f->precision < 0)
		ft_print_d_left(f, n, '0', length_n);
	else if (f->flags[0] == '0')
		ft_print_d_left(f, n, ' ', length_n);
	else if (f->flags[0] == '-')
		ft_print_d_right(f, n, ' ', length_n);
	else
		ft_print_d_left(f, n, ' ', length_n);
}

void	ft_u(t_format *f, unsigned int n)
{
	if (f->precision == 0 && n == 0)
		f->length += ft_write_s_z(' ', f->width);
	else if (f->flags[0] == '0' && f->precision < 0)
		ft_print_u_left(f, n, '0');
	else if (f->flags[0] == '0')
		ft_print_u_left(f, n, ' ');
	else if (f->flags[0] == '-')
		ft_print_u_right(f, n, ' ');
	else
		ft_print_u_left(f, n, ' ');
}

void	ft_p(t_format *f, unsigned long long n)
{
	if (f->precision == 0 && n == 0 && f->flags[0] != '-')
	{
		f->length += ft_write_s_z(' ', f->width - f->precision - 2) + 2;
		write(1, "0x", 2);
	}
	else if (f->precision == 0 && n == 0)
	{
		write(1, "0x", 2);
		f->length += ft_write_s_z(' ', f->width - f->precision - 2) + 2;
	}
	else if (f->flags[0] == '0' && f->precision < 0)
		ft_print_p_left(f, n, '0');
	else if (f->flags[0] == '0')
		ft_print_p_left(f, n, ' ');
	else if (f->flags[0] == '-')
		ft_print_p_right(f, n, ' ');
	else
		ft_print_p_left(f, n, ' ');
}

void	ft_hexa(t_format *f, unsigned int n, char hexa)
{
	if (f->precision == 0 && n == 0)
		f->length += ft_write_s_z(' ', f->width);
	else if (f->flags[0] == '0' && f->precision < 0)
		ft_print_hexa_left(f, n, '0', hexa);
	else if (f->flags[0] == '0')
		ft_print_hexa_left(f, n, ' ', hexa);
	else if (f->flags[0] == '-')
		ft_print_hexa_right(f, n, ' ', hexa);
	else
		ft_print_hexa_left(f, n, ' ', hexa);
}

void	ft_percent(t_format *f, char c)
{
	if (f->flags[0] == '-')
		ft_print_percent_right(f, c, ' ');
	else if (f->flags[0] == '0')
		ft_print_percent_left(f, c, '0');
	else
		ft_print_percent_left(f, c, ' ');
}
