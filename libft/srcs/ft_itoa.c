/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:10:41 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/17 14:10:42 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strnum(int n)
{
	int				i;
	int				cmp;
	unsigned int	tmp;

	i = 0;
	cmp = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		tmp = n * -1;
		cmp = 1;
	}
	else
		tmp = n;
	while (tmp >= 1)
	{
		tmp /= 10;
		i++;
	}
	return (i + cmp);
}

static char		*ft_revstr(char *str)
{
	int		i;
	char	tmp;
	int		length;

	length = ft_strlen(str);
	i = 0;
	while (str[i] && i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = tmp;
		i++;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char			*new_str;
	int				i;
	int				len;
	unsigned int	tmp_nbr;

	i = -1;
	len = ft_strnum(n);
	if (!(new_str = malloc((len + 1) * sizeof(char))))
		return (0);
	if (n < 0)
	{
		tmp_nbr = n * -1;
		len--;
	}
	else
		tmp_nbr = n;
	while (++i < len)
	{
		new_str[i] = tmp_nbr % 10 + '0';
		tmp_nbr /= 10;
	}
	if (n < 0)
		new_str[i++] = '-';
	new_str[i] = '\0';
	return (ft_revstr(new_str));
}
