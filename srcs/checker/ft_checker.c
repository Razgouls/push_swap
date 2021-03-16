/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:58:14 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/16 19:50:53 by eoliveir         ###   ########.fr       */
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
		ft_free_list(&d.a);
	}
	ft_print_stack(d.a);
	return (0);
}