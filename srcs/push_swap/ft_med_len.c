/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_med_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 07:37:22 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/29 12:26:55 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_print_infos(t_data *d)
{
	printf("-------------------INFOS-------------------\n");
	printf("a : ");
	ft_print_stack(d->a);
	printf("b : ");
	ft_print_stack(d->b);
	printf("-------------------------------------------\n");
}

void			ft_sort_elem_list(t_data *d, int *cmp)
{
	while (d->b)
	{
		if (d->b->nbr < ft_get_last_list(d->a)->nbr &&
			d->b->nbr > ft_get_last_list(d->a)->prev->nbr)
		{
			ft_before_last(d);
			(*cmp) += 4;
		}
		else if (d->len_a >= 3 && d->b->nbr > d->a->nbr &&
			d->b->nbr > d->a->next->nbr && d->b->nbr < d->a->next->next->nbr)
		{
			ft_third_pos(d);
			(*cmp) += 4;
		}
		else
		{
			ft_pa(d);
			(*cmp) += 1;
			ft_small_len(d, cmp);
		}
	}
}

void			ft_max_below(t_data *d, int *cmp)
{
	int			place;

	place = ft_get_place(d->a, ft_get_nbr(d->a, d, 1), 0);
	if (place > d->len_a / 2)
	{
		while (place < d->len_a)
		{
			ft_rra(d, 0, &d->a);
			(*cmp)++;
			place++;
		}
	}
	else
	{
		while (place > 0)
		{
			ft_ra(d, 0, &d->a);
			(*cmp)++;
			place--;
		}
	}
}

int				ft_med_len(t_data *d)
{
	int			cmp;

	cmp = 0;
	if (d->len_a >= 5)
	{
		ft_max_below(d, &cmp);
		ft_pb(d);
		ft_pb(d);
		cmp += 2;
		ft_small_len_b(d, &cmp);
		ft_small_len(d, &cmp);
		ft_sort_elem_list(d, &cmp);
	}
	if (cmp > 1)
		return (cmp);
	return (ft_issorted(d, d->a));
}