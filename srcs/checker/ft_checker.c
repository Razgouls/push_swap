/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:58:14 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/31 06:52:03 by eoliveir         ###   ########.fr       */
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

int				ft_call_fcnt(t_data *d)
{
	int			cmp;

	cmp = 0;
	if (ft_issorted(d, d->a) == -1)
	{
		if (d->len_a <= 3)
			return (ft_small_len(d, &cmp));
		else if (d->len_a == 4)
			return (ft_tri_insertion(d, 20));
		else if (d->len_a == 5)
			return (ft_med_len(d));
		//else if (d->len_a <= 100)
		//	ft_long_len(d);
		//else
		//	ft_very_long_len(d);
	}
	return (0);
}

void			ft_testeur(t_data *d, int n, int rep)
{
	int			i;
	char		*buffer;
	t_stack		*stack_tmp;
	int			res;

	i = 0;
	stack_tmp = NULL;
	(void)rep;
	buffer = malloc(2048 * sizeof(char));
	while (i < rep)
	{
		ft_init_data(d);
		ft_random_nbr(d, n, n * 2);
		ft_copy_list(&stack_tmp, d->a);
		res = ft_call_fcnt(d);
		if (res == -1 || res >= 1)
		{
			printf("------------------------INFOS------------------------\n");
			ft_print_stack(stack_tmp);
			ft_print_stack(d->a);
			printf("coups : [ %d ]\n", res);
			printf("[ KO ]\n");
			printf("-----------------------------------------------------\n");
		}
		printf("res : [ %d ]\n", res);
		ft_free_list(&d->a);
		ft_free_list(&d->b);
		ft_free_list(&stack_tmp);
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_data		d;
	int			ret;

	ret = 0;
	(void)argv;
	(void)argc;
	//ft_testeur(&d, 4, 1);
	ft_random_nbr(&d, 100, 400);
	//ft_quick_sort(&d);
	//ft_divise_list(&d, d.a);
	//ft_radix_sort(&d);
	//ft_print_stack(d.a);
	//ft_init_data(&d);
	/*if (argc < 2)
		return (0);
	if (ft_fill_stack(argv + 1, &d) == -1)
	{
		write(1, "Error\n", 6);
		ft_free_list(&d.a);
		return (-1);
	}*/
	//ft_random_nbr(&d);
	//ft_loop(&d);
	//ft_tri_insertion(&d, 250);
	int		count = 0;

	/*count += ft_tri_insertion(&d, 50);
	count += ft_tri_insertion_b(&d, 25);
	count += ft_tri_insertion(&d, 10);
	count += ft_tri_insertion_b(&d, 1);*/

	count += ft_tri_insertion(&d, 25);
	count += ft_tri_insertion_b(&d, 1);
	printf("count : [ %d ]\n", count);
	if (ft_issorted(&d, d.a) == -1)
		printf("[ KO ]\n");
	else
		printf("[ OK ]\n");
	//ft_print_stack(d.a);
	//ft_call_fcnt(&d);
	//ft_radix_sort(&d);
	//ft_small_len(&d);
	//ft_free_list(&d.a);
	//ft_free_list(&d.b);
	return (0);
}