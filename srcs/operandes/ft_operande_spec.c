/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operande_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:21:22 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/29 12:23:25 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_before_last(t_data *d)
{
	ft_rra(d, 0, &d->a);
	ft_pa(d);
	ft_ra(d, 0, &d->a);
	ft_ra(d, 0, &d->a);
}

void			ft_third_pos(t_data *d)
{
	ft_ra(d, 0, &d->a);
	ft_pa(d);
	ft_sa(d);
	ft_rra(d, 0, &d->a);
}