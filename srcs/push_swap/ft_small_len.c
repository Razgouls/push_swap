/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 06:52:38 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/30 20:13:39 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int				ft_small_len(t_data *d, int *cmp)
{
	t_stack		*c;

	c = d->a;
	if (d->len_a == 2 && ft_issorted(d, d->a) == -1)
	{
		ft_sa(d);
		(*cmp)++;
	}
	else if (d->len_a > 2 && ft_issorted(d, d->a) == -1)
	{
		if (c->nbr < c->next->nbr && c->nbr < c->next->next->nbr &&
			c->next->nbr > c->next->next->nbr)
		{
			ft_rra(d, 0, &d->a);
			ft_sa(d);
			(*cmp) += 2;
		}
		else if (c->nbr > c->next->nbr && c->nbr < c->next->next->nbr)
		{
			ft_sa(d);
			(*cmp)++;
		}
		else if (c->nbr > c->next->nbr && c->next->nbr < c->next->next->nbr)
		{
			ft_ra(d, 0, &d->a);
			(*cmp)++;
		}
		else if (c->nbr < c->next->nbr && c->nbr > c->next->next->nbr)
		{
			ft_rra(d, 0, &d->a);
			(*cmp)++;
		}
		else if (c->nbr > c->next->nbr && c->next->nbr > c->next->next->nbr)
		{
			ft_sa(d);
			ft_rra(d, 0, &d->a);
			(*cmp) += 2;
		}
	}
	return (ft_issorted(d, d->a));
}

int			ft_small_len_b(t_data *d, int *cmp)
{
	t_stack		*c;

	c = d->b;
	if (d->len_b == 2 && ft_issorted(d, d->b) == -1)
	{
		ft_sb(d);
		(*cmp)++;
	}
	else if (d->len_b > 2 && ft_issorted(d, d->b) == -1)
	{
		if (c->nbr > c->next->nbr && c->nbr > c->next->next->nbr &&
			c->next->nbr < c->next->next->nbr)
		{
			ft_rrb(d, 1, &d->b);
			ft_sb(d);
			(*cmp) += 2;
		}
		else if (c->nbr < c->next->nbr && c->nbr > c->next->next->nbr)
		{
			ft_sb(d);
			(*cmp)++;
		}
		else if (c->nbr < c->next->nbr && c->next->nbr > c->next->next->nbr)
		{
			ft_rb(d, 1, &d->b);
			(*cmp)++;
		}
		else if (c->nbr > c->next->nbr && c->nbr < c->next->next->nbr)
		{
			ft_rrb(d, 1, &d->b);
			(*cmp)++;
		}
		else if (c->nbr < c->next->nbr && c->next->nbr < c->next->next->nbr)
		{
			ft_sb(d);
			ft_rrb(d, 1, &d->b);
			(*cmp) += 2;
		}
	}
	return (ft_issorted(d, d->b));
}

int			ft_small_len_a(t_data *d, int *cmp)
{
	t_stack		*c;

	c = d->a;
	if (d->len_a == 2 && ft_issorted(d, d->a) == -1)
	{
		ft_sa(d);
		(*cmp)++;
	}
	else if (d->len_a > 2 && ft_issorted(d, d->a) == -1)
	{
		if (c->nbr > c->next->nbr && c->nbr > c->next->next->nbr &&
			c->next->nbr < c->next->next->nbr)
		{
			ft_rra(d, 0, &d->a);
			ft_sa(d);
			(*cmp) += 2;
		}
		else if (c->nbr < c->next->nbr && c->nbr > c->next->next->nbr)
		{
			ft_sa(d);
			(*cmp)++;
		}
		else if (c->nbr < c->next->nbr && c->next->nbr > c->next->next->nbr)
		{
			ft_ra(d, 0, &d->a);
			(*cmp)++;
		}
		else if (c->nbr > c->next->nbr && c->nbr < c->next->next->nbr)
		{
			ft_rra(d, 0, &d->a);
			(*cmp)++;
		}
		else if (c->nbr < c->next->nbr && c->next->nbr < c->next->next->nbr)
		{
			ft_sa(d);
			ft_rra(d, 0, &d->a);
			(*cmp) += 2;
		}
	}
	return (ft_issorted(d, d->a));
}

int				ft_small_len_b_bis(t_data *d, int *cmp)
{
	t_stack		*c;

	c = d->b;
	if (d->len_b == 2 && ft_issorted(d, d->b) == -1)
	{
		ft_sb(d);
		(*cmp)++;
	}
	else if (d->len_b > 2 && ft_issorted(d, d->b) == -1)
	{
		if (c->nbr < c->next->nbr && c->nbr < c->next->next->nbr &&
			c->next->nbr > c->next->next->nbr)
		{
			ft_rrb(d, 1, &d->b);
			ft_sb(d);
			(*cmp) += 2;
		}
		else if (c->nbr > c->next->nbr && c->nbr < c->next->next->nbr)
		{
			ft_sb(d);
			(*cmp)++;
		}
		else if (c->nbr > c->next->nbr && c->next->nbr < c->next->next->nbr)
		{
			ft_rb(d, 1, &d->b);
			(*cmp)++;
		}
		else if (c->nbr < c->next->nbr && c->nbr > c->next->next->nbr)
		{
			ft_rrb(d, 1, &d->b);
			(*cmp)++;
		}
		else if (c->nbr > c->next->nbr && c->next->nbr > c->next->next->nbr)
		{
			ft_sb(d);
			ft_rrb(d, 1, &d->b);
			(*cmp) += 2;
		}
	}
	return (ft_issorted(d, d->b));
}