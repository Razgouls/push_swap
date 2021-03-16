/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 08:44:18 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/26 09:51:42 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_str(char c, int width, int precision, char *str)
{
	int	i;

	i = 0;
	while (str[i] && i < precision)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	while (i < width)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}

int		ft_print_str_bis(char c, int width, int precision, char *str)
{
	int	i;
	int tmp;

	i = 0;
	tmp = 0;
	while (tmp < width)
	{
		ft_putchar_fd(c, 1);
		tmp++;
	}
	while (str[i] && i < precision)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i + tmp);
}
