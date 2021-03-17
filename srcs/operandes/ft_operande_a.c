/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operande_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 08:38:04 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/17 14:25:54 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_sa(t_data *d)
{
	t_stack		*tmp;

	if (d->len_a < 2)
		return ;
	tmp = (d->a)->next;
	tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	tmp->next = d->a;
	tmp->prev->prev = tmp;
	tmp->prev = NULL;
	d->a = tmp;
}

void			ft_pa(t_data *d)
{
	t_stack		*tmp;

	if (d->len_b < 1)
		return ;
	tmp = d->a;
	ft_add_front_list(d, 0, &d->a, d->b->nbr);
	ft_delete_elem_first(d, &d->b, 1);
}

void			ft_ra(t_data *d, int id, t_stack **s)
{
	t_stack		*tmp;
	t_stack		*current;

	if (id == 0 && d->len_a < 2)
		return ;
	if (id == 1 && d->len_b < 2)
		return ;
	tmp = *s;
	(*s)->next->prev = NULL;
	current = *s;
	while (current->next)
		current = current->next;
	current->next = tmp;
	*s = (*s)->next;
	current->next->next = NULL;
	current->next->prev = current;
}

void			ft_rra(t_data *d, int id, t_stack **s)
{
	t_stack		*tmp;
	t_stack		*current;

	if (id == 0 && d->len_a < 2)
		return ;
	if (id == 1 && d->len_b < 2)
		return ;
	tmp = *s;
	current = *s;
	while (current->next)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = tmp;
	tmp->prev = current;
	*s = current;
}