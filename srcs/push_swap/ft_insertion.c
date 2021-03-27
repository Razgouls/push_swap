/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:19:46 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/27 09:36:15 by eoliveir         ###   ########.fr       */
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

void			ft_random_nbr(t_data *d)
{
	int		cmp;
	int		nbr;

	cmp = 0;
	srand(time(NULL));
	while (cmp < 100)
	{
		nbr = rand() % 130 + 1;
		if (ft_get_inside(nbr, d->a) == -1)
		{
			ft_add_back_list(d, 0, &d->a, nbr);
			cmp++;
		}
	}
	ft_print_stack(d->a);
}

int				ft_tri_insertion(t_data *d)
{
	int		place;
	int		cmp;
	int		res;
	int		i;

	i = 1;
	res = 0;
	cmp = 0;
	ft_random_nbr(d);
	while (d->a)
	{
		place = ft_get_place(d->a, ft_get_nbr(d->a, d, 0), 0);
		printf("place : [ %d ]\n", place);
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
	ft_print_stack(d->b);
	printf("res : [ %d ]\n", res);
	return (0);
}

//1. no more than 2-3 operations for 3 integers
//2. no more than 12 operations for 5 integers
//3. no more than 700 operations for 100 integers
//4. no more than 5300 operations for 500 integers