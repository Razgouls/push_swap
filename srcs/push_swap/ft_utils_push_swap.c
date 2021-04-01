/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 07:53:03 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 09:44:43 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"
#include "../../includes/push_swap.h"

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

int				ft_get_nbr(t_stack *s, t_stack *s2, int id)
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
			if (current->nbr < nbr && ft_get_inside(current->nbr, s2) == -1)
				nbr = current->nbr;
		}
		else
		{
			if (current->nbr > nbr && ft_get_inside(current->nbr, s2) == -1)
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
			break ;
		current = current->next;
	}
	if (id == 0)
		return (cmp);
	return (current->nbr);
}

int				ft_get_best_place(t_stack *s, int n, int len)
{
	t_stack		*current;
	int			nbr;
	int			place;
	int			tmp_p;

	nbr = 0;
	current = s;
	nbr = current->nbr;
	place = -1;
	while (current)
	{
		if (current->nbr >= n)
		{
			tmp_p = ft_get_place(s, current->nbr, 0);
			if ((tmp_p < place && tmp_p < len - place) || place == -1)
			{
				place = tmp_p;
			}
		}
		current = current->next;
	}
	return (place);
}
