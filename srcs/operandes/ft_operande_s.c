/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operande_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 08:38:10 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/29 11:10:25 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_ss(t_data *d)
{
	ft_sa(d);
	ft_sb(d);
//	printf("ss\n");
}

void			ft_rr(t_data *d)
{
	ft_ra(d, 0, &d->a);
	ft_rb(d, 1, &d->b);
//	printf("rr\n");
}

void			ft_rrr(t_data *d)
{
	ft_rra(d, 0, &d->a);
	ft_rrb(d, 1, &d->b);
	//printf("rrr\n");
}