/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operande_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 08:38:10 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/17 14:28:54 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_ss(t_data *d)
{
	ft_sa(d);
	ft_sb(d);
}

void			ft_rr(t_data *d)
{
	ft_ra(d, 0, &d->a);
	ft_rb(d, 1, &d->b);
}

void			ft_rrr(t_data *d)
{
	ft_rra(d, 0, &d->a);
	ft_rrb(d, 1, &d->b);
}