/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:03:33 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/17 14:35:28 by eoliveir         ###   ########.fr       */
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

void			ft_modif_elem(t_stack *cur, t_stack *next, t_stack *prev)
{
	cur->prev = prev;
	cur->next = next;
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
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (-1);
		a = a->next;
	}
	return (0);
}

void			ft_add_front_list(t_data *d, int id, t_stack **s, int nbr)
{
	t_stack		*new;

	if (*s)
	{
		new = ft_new_elem(*s, NULL, nbr);
		(*s)->prev = new;
	}
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

	if ((*s)->next)
	{
		tmp = *s;
		if (tmp->next)
			*s = tmp->next;
		else
			(*s) = NULL;
		(*s)->prev = NULL;
		ft_memdel(tmp);
		ft_setup_len(d, id, '-');
	}
	else
	{
		ft_memdel(*s);
		*s = NULL;
		ft_setup_len(d, id, '-');
	}
}