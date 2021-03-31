/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:28:39 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/30 20:14:14 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int				ft_get_inside_radix(int nbr, t_stack *s)
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

int				ft_get_number(int nbr, int index)
{
	int			i;
	int			tmp_n;
	int			res;

	tmp_n = nbr;
	i = 0;
	while (i < index)
	{
		tmp_n /= 10;
		i++;
	}
	res = tmp_n % 10;
	return (res);
}

int				ft_get_nbr_radix(t_stack *s)
{
	t_stack		*current;
	int			nbr;

	nbr = 0;
	current = s;
	nbr = current->nbr;
	while (current)
	{
		if (current->nbr > nbr)
			nbr = current->nbr;
		current = current->next;
	}
	return (nbr);
}

int				ft_len_number(int nbr)
{
	int			cmp;

	cmp = 0;
	while (nbr >= 1)
	{
		nbr /= 10;
		cmp++;
	}
	return (cmp);
}

void			ft_random_nbr_radix(t_data *d)
{
	/*ft_add_back_list(d, 0, &d->a, 10);
	ft_add_back_list(d, 0, &d->a, 4);
	ft_add_back_list(d, 0, &d->a, 8);
	ft_add_back_list(d, 0, &d->a, 5);
	ft_add_back_list(d, 0, &d->a, 12);
	ft_add_back_list(d, 0, &d->a, 2);
	ft_add_back_list(d, 0, &d->a, 6);
	ft_add_back_list(d, 0, &d->a, 11);
	ft_add_back_list(d, 0, &d->a, 3);
	ft_add_back_list(d, 0, &d->a, 9);
	ft_add_back_list(d, 0, &d->a, 7);
	ft_add_back_list(d, 0, &d->a, 1);*/

	/*ft_add_back_list(d, 0, &d->a, 11);
	ft_add_back_list(d, 0, &d->a, 1);
	ft_add_back_list(d, 0, &d->a, 7);
	ft_add_back_list(d, 0, &d->a, 9);
	ft_add_back_list(d, 0, &d->a, 3);
	ft_add_back_list(d, 0, &d->a, 6);
	ft_add_back_list(d, 0, &d->a, 2);
	ft_add_back_list(d, 0, &d->a, 4);
	ft_add_back_list(d, 0, &d->a, 5);
	ft_add_back_list(d, 0, &d->a, 8);
	ft_add_back_list(d, 0, &d->a, 10);
	ft_add_back_list(d, 0, &d->a, 12);*/
	int		cmp;
	int		nbr;

	cmp = 0;
	srand(time(NULL));
	while (cmp < 15)
	{
		nbr = rand() % 200 + 1;
		if (ft_get_inside_radix(nbr, d->a) == -1)
		{
			ft_add_back_list(d, 0, &d->a, nbr);
			cmp++;
		}
	}
	ft_print_stack(d->a);
}

int				ft_get_place_radix(t_stack *s, int nbr, int id)
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

int				ft_push_index_a(t_data *d, int nbr, int *res)
{
	t_stack		*current;
	int			place;
	int			i;

	i = -1;
	current = d->a;
	place = ft_get_place_radix(d->a, nbr, 0);
	if (place > d->len_a / 2)
	{
		while (place < d->len_a)
		{
			ft_rra(d, 0, &d->a);
			place++;
			(*res)++;
		}
	}
	else
	{
		while (place > 0)
		{
			ft_ra(d, 0, &d->a);
			place--;
			(*res)++;
		}
	}
	ft_pb(d);
	(*res)++;
	return (0);
}

int				ft_push_index_b(t_data *d, int nbr, int *res)
{
	t_stack		*current;
	int			place;
	int			i;
	int			tmp_p;

	i = -1;
	current = d->b;
	place = ft_get_place_radix(d->b, nbr, 0);
	tmp_p = place;
	if (place > d->len_b / 2)
	{
		while (place < d->len_b / 2)
		{
			ft_rrb(d, 1, &d->b);
			place++;
			(*res)++;
		}
	}
	else
	{
		while (place > 0)
		{
			ft_rb(d, 1, &d->b);
			place--;
			(*res)++;
		}

	}
	ft_pa(d);
	(*res)++;
	return (0);
}

int				ft_radix_sort_aux(t_data *d, t_stack *s, int j, int id, int *res)
{
	int			i;
	int			inc_n;
	int			tmp_n;
	t_stack		*current;

	(void)s;
	i = 0;
	inc_n = 0;
	while (inc_n < 10)
	{
		if (id % 2 == 0)
			current = d->a;
		else
			current = d->b;
		while (current)
		{
			tmp_n = ft_get_number(current->nbr, j);
			if (tmp_n == inc_n)
			{
				if (id % 2 == 0)
					ft_push_index_a(d, current->nbr, res);
				else
				{
					ft_push_index_b(d, current->nbr, res);
				}
			}
			current = current->next;
		}
		inc_n++;
	}
	return (0);
}

int				ft_radix_sort(t_data *d)
{
	int			max;
	int			j;
	int			loop_c;
	int			res;

	res = 0;
	j = 0;
	//ft_random_nbr_radix(d);
	max = ft_get_nbr_radix(d->a);
	loop_c = ft_len_number(max);
	while (j < loop_c)
	{
		if (j % 2 == 0)
			ft_radix_sort_aux(d, d->a, j, 0, &res);
		else
			ft_radix_sort_aux(d, d->b, j, 1, &res);
		j++;
	}
	printf("res_radix : [ %d ]\n", res);
	if (loop_c % 2 == 1)
		ft_tri_insertion_b(d, 10);
	else
		ft_tri_insertion(d, 10);
	//ft_print_stack(d->a);
	//ft_print_stack(d->b);
	return (0);
}