/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:49:40 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/03 09:48:54 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_u(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

int		ft_printf_aux(const char *s, int i, va_list ap, int *length)
{
	int			index;
	t_format	f;

	index = 1;
	f = ft_init_struct();
	ft_flags_field(s + i, &f, &index, 0);
	ft_width_field(s + i, &f, &index, ap);
	ft_precision_field(s + i, &f, &index, ap);
	ft_type_field(s + i, &f, &index);
	ft_print_types_field(ap, &f);
	(*length) += f.length;
	return (index);
}

int		ft_printf(const char *s, ...)
{
	int			i;
	int			tab[2];
	int			length;
	va_list		ap;

	i = 0;
	length = 0;
	tab[0] = 0;
	tab[1] = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			tab[0] = ft_printf_aux(s, i, ap, &length);
			tab[1] += tab[0];
			i += tab[0];
			if (!s[i])
				break ;
		}
		else
			ft_putchar_fd(s[i++], 1);
	}
	return (i - tab[1] + length);
}
