/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 00:55:37 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/05 00:55:38 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base2(char *str)
{
	int m;
	int p;

	m = 0;
	p = 0;
	while (str[m])
	{
		while (str[p])
		{
			if ((str[p] == '+' || str[p] == '-') ||
					(str[m] == str[p] && m != p) ||
					(str[p] >= 9 && str[p] <= 13) ||
					(str[p] == ' '))
				return (1);
			p++;
		}
		p = 0;
		m++;
	}
	return (0);
}

static int	inside_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	search_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int			ft_atoi_base(char *str, char *base)
{
	int i;
	int cmp;
	int resultat;

	i = 0;
	cmp = 1;
	resultat = 0;
	if (check_base2(base) == 1)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cmp *= -1;
		i++;
	}
	while (str[i] && inside_base(base, str[i]) == 1)
	{
		resultat *= ft_strlen(base);
		resultat += search_base(base, str[i]);
		i++;
	}
	return (resultat * cmp);
}
