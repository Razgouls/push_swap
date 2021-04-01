/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 07:08:32 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 07:13:12 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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

void			ft_add_back_list_bis(t_stack **s, int nbr)
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

void			ft_copy_list(t_stack **dest, t_stack *src)
{
	t_stack		*current;

	current = src;
	while (current)
	{
		ft_add_back_list_bis(dest, current->nbr);
		current = current->next;
	}
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
