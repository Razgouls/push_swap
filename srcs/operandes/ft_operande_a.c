/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operande_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 08:38:04 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/17 10:06:38 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_sa(t_data *d, t_stack **a)
{
	t_stack		*tmp;

	if (d->len_a < 2)
		return ;
	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	*a = tmp;
	(*a)->next = tmp->prev;
}

void			ft_pa(t_data *d, t_stack **a, t_stack **b)
{
	t_stack		*tmp;

	if (d->len_b < 1)
		return ;
	tmp = *a;
	ft_add_front_list(d, 0, a, (*b)->nbr);
	ft_delete_elem_first(d, b, 1);
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
	current = *s;
	while (current->next)
		current = current->next;
	current->next = tmp;
	*s = tmp->next;
	tmp->next = NULL;
}

void			ft_rra(t_data *d, int id, t_stack **s)
{
	t_stack		*tmp;
	t_stack		*current;

	ft_print_stack(*s);
	if (id == 0 && d->len_a < 2)
		return ;
	if (id == 1 && d->len_b < 2)
		return ;
	tmp = *s;
	current = *s;
	while (current->next)
		current = current->next;
	//current->prev->next = NULL;
	//*s = current;
	//(*s)->next = tmp;
}