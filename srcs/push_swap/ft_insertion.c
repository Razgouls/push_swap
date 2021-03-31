/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:19:46 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/31 06:59:00 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int				ft_get_inside(int nbr, t_stack *s)
{
	t_stack		*current;

	current = s;
	while (current)
	{
		if (current->nbr == nbr)
			return (0);
		current = current->next;
	}
	return (-1);
}

int				ft_get_nbr(t_stack *s, t_data *d, int id)
{
	t_stack		*current;
	int			nbr;

	nbr = 0;
	current = s;
	nbr = current->nbr;
	while (current)
	{
		if (id == 0)
		{
			if (current->nbr < nbr && ft_get_inside(current->nbr, d->b) == -1)
				nbr = current->nbr;
		}
		else
		{
			if (current->nbr > nbr && ft_get_inside(current->nbr, d->b) == -1)
				nbr = current->nbr;
		}
		current = current->next;
	}
	return (nbr);
}

int				ft_get_nbr_b(t_stack *s, t_data *d, int id)
{
	t_stack		*current;
	int			nbr;

	nbr = 0;
	current = s;
	nbr = current->nbr;
	while (current)
	{
		if (id == 0)
		{
			if (current->nbr < nbr && ft_get_inside(current->nbr, d->a) == -1)
				nbr = current->nbr;
		}
		else
		{
			if (current->nbr > nbr && ft_get_inside(current->nbr, d->a) == -1)
				nbr = current->nbr;
		}
		current = current->next;
	}
	return (nbr);
}

int				ft_get_intervalle(t_stack *s, t_data *d, int n)
{
	int			max;
	
	max = ft_get_nbr(s, d, 1);
	return ((max / 5) * n);
}

int				ft_get_place(t_stack *s, int nbr, int id)
{
	t_stack		*current;
	int			cmp;

	current = s;
	cmp = 0;
	current = s;
	while (current)
	{
		if (current->nbr != nbr)
			cmp++;
		else
			break;
		current = current->next;
	}
	if (id == 0)
		return (cmp);
	return (current->nbr);
}

int				ft_get_best_place(t_stack *s, t_data *d, int n)
{
	t_stack		*current;
	int			nbr;
	int			place;
	int			tmp_p;

	nbr = 0;
	current = s;
	nbr = current->nbr;
	place = -1;
	while (current)
	{
		if (current->nbr >= n)
		{
			tmp_p = ft_get_place(s, current->nbr, 0);
			if ((tmp_p < place && tmp_p < d->len_a - place) || place == -1)
			{
				place = tmp_p;
			}
		}
		current = current->next;
	}
	return (place);
}

int				ft_get_best_place_b(t_stack *s, t_data *d, int n)
{
	t_stack		*current;
	int			nbr;
	int			place;
	int			tmp_p;

	nbr = 0;
	current = s;
	nbr = current->nbr;
	place = -1;
	while (current)
	{
		if (current->nbr >= n)
		{
			tmp_p = ft_get_place(s, current->nbr, 0);
			if ((tmp_p < place && tmp_p < d->len_b - place) || place == -1)
			{
				place = tmp_p;
			}
		}
		current = current->next;
	}
	return (place);
}

void			ft_random_nbr(t_data *d, int n, int max)
{
	int		cmp;
	int		nbr;

	cmp = 0;
	struct timeval tpstart;
	gettimeofday(&tpstart, NULL);
	srand(tpstart.tv_usec); 
	while (cmp < n)
	{
		nbr = 0;
		nbr = rand() % max;
		if (ft_get_inside(nbr, d->a) == -1)
		{
			ft_add_back_list(d, 0, &d->a, nbr);
			cmp++;
		}
	}
}

int				ft_tri_insertion(t_data *d, int max)
{
	int		place;
	int		cmp;
	int		res;
	int		i;
	int		nbr_max;

	res = 0;
	cmp = 0;
	nbr_max = ft_get_nbr(d->a, d, 1) + 1;
	while (d->a)
	{
		i = nbr_max;
		while (d->a && (place = ft_get_best_place(d->a, d, i)) == -1)
			i -= max;
		if (place > d->len_a / 2)
		{
			while (place < d->len_a)
			{
				ft_rra(d, 0, &d->a);
				res++;
				place++;
			}
		}
		else
		{
			while (place > 0)
			{
				ft_ra(d, 0, &d->a);
				res++;
				place--;
			}
		}
		ft_pb(d);
		res++;
	}
	return (res);
}

int				ft_tri_insertion_b(t_data *d, int max)
{
	int		place;
	int		cmp;
	int		res;
	int		i;
	int		nbr_max;

	res = 0;
	cmp = 0;
	nbr_max = ft_get_nbr_b(d->b, d, 1) + 1;
	while (d->b)
	{
		i = nbr_max;
		while (d->b && (place = ft_get_best_place_b(d->b, d, i)) == -1)
			i -= max;
		if (place > d->len_b / 2)
		{
			while (place < d->len_b)
			{
				ft_rrb(d, 1, &d->b);
				res++;
				place++;
			}
		}
		else
		{
			while (place > 0)
			{
				ft_rb(d, 1, &d->b);
				res++;
				place--;
			}
		}
		ft_pa(d);
		res++;
	}
	return (res);
}