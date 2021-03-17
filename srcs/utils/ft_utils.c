/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:23:51 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/17 09:10:56 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int				ft_check_number(char *str)
{
	if (str[0] <= '2' && str[1] <= '1' && str[2] <= '4' && str[3] <= '7' &&
		str[4] <= '4' && str[5] <= '8' && str[6] <= '3' && str[7] <= '6' &&
		str[8] <= '4' && str[9] <= '7')
		return (0);
	return (-1);
}

void			ft_memdel(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void			ft_setup_len(t_data *d, int id, char op)
{
	if (op == '+')
	{
		if (id == 0)
			d->len_a++;
		else
			d->len_b++;
	}
	else if (op == '-')
	{
		if (id == 0)
			d->len_a--;
		else
			d->len_b--;
	}
}