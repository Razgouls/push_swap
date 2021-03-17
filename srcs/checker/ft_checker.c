/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:58:14 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/17 10:06:22 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_init_data(t_data *d)
{
	d->len_a = 0;
	d->len_b = 0;
	d->a = NULL;
	d->b = NULL;
}

int				main(int argc, char **argv)
{
	t_data		d;

	ft_init_data(&d);
	if (argc < 2)
		return (0);
	if (ft_fill_stack(argv + 1, &d) == -1)
	{
		write(2, "Error\n", 6);
		ft_free_list(&d.b);
		return (-1);
	}
	//ft_print_stack(d.a);
	ft_print_stack(d.b);
	ft_ra(&d, 1, &(d.b));
	ft_rra(&d, 1, &(d.b));
	//ft_print_stack(d.a);
	ft_print_stack(d.b);
	ft_free_list(&d.a);
	ft_free_list(&d.b);
	return (0);
}