/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:12:43 by eoliveir          #+#    #+#             */
/*   Updated: 2021/02/01 13:18:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lennumber_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_atoi_new_str(char const *s)
{
	char	*new_str;
	int		i;

	i = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	new_str = ft_substr(s, 0, i);
	if (!new_str)
		return (-1);
	return (ft_atoi(new_str));
}

void	ft_convert_hexa(unsigned long long n, char hexa)
{
	char	*base;

	base = "0123456789abcdef";
	if (hexa == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_convert_hexa(n / 16, hexa);
		ft_convert_hexa(n % 16, hexa);
	}
	else
		write(1, base + n, 1);
}

int		ft_convert_hexa_len(unsigned long long nb)
{
	int				cmp;

	cmp = 0;
	while (nb >= 16)
	{
		nb /= 16;
		cmp++;
	}
	return (++cmp);
}
