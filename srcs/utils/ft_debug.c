/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:29:38 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/31 10:05:29 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_print_stack(t_stack *s)
{
	while (s)
	{
		printf("[ %d ] ", s->nbr);
		s = s->next;
	}
	printf("\n");
}

void			ft_print_stack_inv(t_stack *s)
{
	while (s->next)
		s = s->next;
	while (s)
	{
		printf("[ %d ] ", s->nbr);
		s = s->prev;
	}
	printf("\n");
}