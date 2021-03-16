/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:03:33 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/16 19:55:13 by eoliveir         ###   ########.fr       */
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

void			ft_add_back_list(t_stack **s, int nbr)
{
	t_stack		*current;

	current = *s;
	if (!current)
	{
		*s = ft_new_elem(NULL, NULL, nbr);
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = ft_new_elem(NULL, current, nbr);
}