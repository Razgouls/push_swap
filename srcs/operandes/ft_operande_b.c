/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operande_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 08:38:08 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/31 17:41:34 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_sb(t_data *d)
{
	t_stack		*tmp;

	if (d->len_b < 2)
		return ;
	tmp = (d->b)->next;
	tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	tmp->next = d->b;
	tmp->prev->prev = tmp;
	tmp->prev = NULL;
	d->b = tmp;
	if (d->input == 1)
		printf("sb\n");
}

void			ft_pb(t_data *d)
{
	t_stack		*tmp;

	if (d->len_a < 1)
		return ;
	tmp = d->b;
	ft_add_front_list(d, 1, &d->b, d->a->nbr);
	ft_delete_elem_first(d, &d->a, 0);
	if (d->input == 1)
		printf("pb\n");
}

void			ft_rb(t_data *d, int id, t_stack **s)
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
	*s = (*s)->next;
	while (current->next)
		current = current->next;
	current->next = tmp;
	current->next->next = NULL;
	current->next->prev = current;
	if (d->input == 1)
		printf("rb\n");
}

void			ft_rrb(t_data *d, int id, t_stack **s)
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
	if (d->input == 1)
		printf("rrb\n");
}
