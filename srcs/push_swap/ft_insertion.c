/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:19:46 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 07:53:32 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int				ft_rotate_list(t_data *d, int id, int len, int place)
{
	int			res;

	res = 0;
	if (place > len / 2)
		while (place < len)
		{
			if (id == 0)
				ft_rra(d, 0, &d->a);
			else
				ft_rrb(d, 1, &d->b);
			res++;
			place++;
		}
	else
		while (place > 0)
		{
			if (id == 0)
				ft_ra(d, 0, &d->a);
			else
				ft_rb(d, 1, &d->b);
			res++;
			place--;
		}
	return (res);
}

int				ft_tri_insertion(t_data *d, int max)
{
	int		place;
	int		res;
	int		i;

	res = 0;
	while (d->a)
	{
		i = ft_get_nbr(d->a, d->b, 1) + 1;
		while (d->a && (place = ft_get_best_place(d->a, i, d->len_a)) == -1)
			i -= max;
		res += ft_rotate_list(d, 0, d->len_a, place);
		ft_pb(d);
		ft_small_len_b_bis(d);
		res++;
	}
	return (res);
}

int				ft_tri_insertion_b(t_data *d, int max)
{
	int		place;
	int		res;
	int		i;

	res = 0;
	while (d->b)
	{
		i = ft_get_nbr(d->b, d->a, 1) + 1;
		while (d->b && (place = ft_get_best_place(d->b, i, d->len_b)) == -1)
			i -= max;
		res += ft_rotate_list(d, 1, d->len_b, place);
		ft_pa(d);
		ft_small_len_a(d);
		res++;
	}
	return (res);
}
