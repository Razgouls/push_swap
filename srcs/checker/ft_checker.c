/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:58:14 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 10:09:18 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_parser(t_data *d, char *line)
{
	if (!ft_strcmp(line, "sa"))
		ft_sa(d);
	else if (!ft_strcmp(line, "sb"))
		ft_sb(d);
	else if (!ft_strcmp(line, "ss"))
		ft_ss(d);
	else if (!ft_strcmp(line, "pa"))
		ft_pa(d);
	else if (!ft_strcmp(line, "pb"))
		ft_pb(d);
	else if (!ft_strcmp(line, "ra"))
		ft_ra(d, 0, &d->a);
	else if (!ft_strcmp(line, "rb"))
		ft_rb(d, 1, &d->b);
	else if (!ft_strcmp(line, "rr"))
		ft_rr(d);
	else if (!ft_strcmp(line, "rra"))
		ft_rra(d, 0, &d->a);
	else if (!ft_strcmp(line, "rrb"))
		ft_rrb(d, 1, &d->b);
	else if (!ft_strcmp(line, "rrr"))
		ft_rrr(d);
	else
		write(1, "Error\n", 6);
}

int				ft_loop(t_data *d)
{
	int			ret;
	char		*line;

	line = NULL;
	while (1)
	{
		if ((ret = ft_get_next_line(0, &line)) == 0 && line[0] == 0)
		{
			if (ft_issorted(d, d->a) == 0)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			return (0);
		}
		else if (ret == 1 && line[0])
		{
			ft_parser(d, line);
			ft_memdel(line);
		}
	}
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
	ft_loop(&d);
	ft_free_list(&d.a);
	ft_free_list(&d.b);
	return (0);
}
