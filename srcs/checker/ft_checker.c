/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:58:14 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/31 17:40:39 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void			ft_init_data(t_data *d)
{
	d->input = 0;
	d->len_a = 0;
	d->len_b = 0;
	d->a = NULL;
	d->b = NULL;
}

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
			ft_print_stack(d->a);
			ft_memdel(line);
		}
	}
}

void			ft_len_5(t_data *d, int *tmp_count, int j)
{
	(*tmp_count) += ft_tri_insertion(d, j);
}

void			ft_len_100(t_data *d, int *tmp_count, int j)
{
	(*tmp_count) += ft_tri_insertion(d, j);
	(*tmp_count) += ft_tri_insertion_b(d, 1);
}

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

	int		count = 100000;
	int		tmp_count = 0;

	int	j = ft_get_nbr(d.a, &d, 0);
	int save_i;
	
	t_stack *tmp;

	int n = ft_get_nbr(d.a, &d, 1);
	tmp = NULL;

	ft_copy_list(&tmp, d.a);
	if (j == -1)
		j--;
	while (++j < n)
	{
		tmp_count = 0;
		if (j < 0)
			ft_len_100(&d, &tmp_count, -j);
		else
			ft_len_100(&d, &tmp_count, j);
		if (tmp_count < count)
		{
			save_i = j;
			count = tmp_count;
		}
		ft_free_list(&d.a);
        ft_free_list(&d.b);
    	ft_copy_list(&(d.a), tmp);
		if (d.len_a > 50 && d.len_a < 500)
			j += 4;
		else if (d.len_a == 500)
			j += 40;
		else
			j += 1;
		if (j == -1)
			j++;
	}
	ft_free_list(&d.a);
	ft_free_list(&d.b);
	ft_copy_list(&(d.a), tmp);
	d.input = 1;
	if (save_i < 0)
		save_i *= -1;
	ft_call_fcnt(&d, save_i);
	return (0);
}
