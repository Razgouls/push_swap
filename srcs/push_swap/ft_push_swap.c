/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:28:30 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 11:00:51 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"
#include "../../includes/push_swap.h"

int				ft_call_fcnt(t_data *d, int j)
{
	int			cmp;

	cmp = 0;
	if (ft_issorted(d, d->a) == -1)
	{
		if (d->len_a <= 3)
			ft_small_len(d);
		else if (d->len_a == 5)
			ft_len_5(d, &cmp, j);
		else
			ft_len_100(d, &cmp, j);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_data		d;
	int			ret;

	ret = 0;
	(void)argv;
	(void)argc;
	ft_init_data(&d);
	if (argc < 2)
		return (0);
	if (ft_fill_stack(argv + 1, &d) == -1)
	{
		write(1, "Error\n", 6);
		ft_free_list(&d.a);
		return (-1);
	}
	ft_get_solut(&d);
	ft_free_list(&d.a);
	ft_free_list(&d.b);
	return (0);
}
