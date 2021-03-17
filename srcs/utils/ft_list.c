/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:03:33 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/17 09:41:54 by eoliveir         ###   ########.fr       */
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

int				ft_size_list(t_stack *stack)
{
	int			cmp;

	cmp = 0;
	while (stack)
	{
		cmp++;
		stack = stack->next;
	}
	return (cmp);
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

void			ft_add_front_list(t_data *d, int id, t_stack **s, int nbr)
{
	t_stack		*new;

	if (*s && (*s)->next)
		new = ft_new_elem((*s)->next, NULL, nbr);
	else
		new = ft_new_elem(NULL, NULL, nbr);
	*s = new;
	ft_setup_len(d, id, '+');
}

void			ft_add_back_list(t_data *d, int id, t_stack **s, int nbr)
{
	t_stack		*current;

	current = *s;
	if (!current)
	{
		*s = ft_new_elem(NULL, NULL, nbr);
		ft_setup_len(d, id, '+');
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = ft_new_elem(NULL, current, nbr);
	ft_setup_len(d, id, '+');
}

void			ft_delete_elem_first(t_data *d, t_stack **s, int id)
{
	t_stack		*tmp;

	ft_print_stack(*s);
	if (*s)
	{
		tmp = *s;
		*s = tmp->next;
		ft_memdel(tmp);
		ft_setup_len(d, id, '-');
		if (id == 0)
			ft_setup_len(d, 1, '+');
		else
			ft_setup_len(d, 0, '+');
	}
}