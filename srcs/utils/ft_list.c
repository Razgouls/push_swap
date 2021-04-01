/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:03:33 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 07:32:14 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_free_list(t_stack **s)
{
	t_stack		*current;
	t_stack		*tmp;

	current = *s;
	while (current)
	{
		tmp = current->next;
		ft_memdel(current);
		current = tmp;
	}
	*s = NULL;
}

t_stack			*ft_get_last_list(t_stack *s)
{
	t_stack		*current;

	current = s;
	while (current->next)
		current = current->next;
	return (current);
}

t_stack			*ft_new_elem(t_stack *next, t_stack *prev, int nbr)
{
	t_stack		*s;

	s = ft_calloc(sizeof(t_stack), 1);
	if (!s)
		return (s);
	s->nbr = nbr;
	s->prev = prev;
	s->next = next;
	return (s);
}

int				ft_issorted(t_data *d, t_stack *a)
{
	if (d->len_a < 2)
		return (0);
	while (a && a->next)
	{
		if (a->nbr > a->next->nbr)
			return (-1);
		a = a->next;
	}
	return (0);
}

void			ft_free_copy(t_data *d, t_stack *tmp)
{
	ft_free_list(&d->a);
	ft_free_list(&d->b);
	ft_copy_list(&(d->a), tmp);
}
