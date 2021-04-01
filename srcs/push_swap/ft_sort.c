/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 07:28:08 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 09:45:12 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"
#include "../../includes/push_swap.h"

void			ft_len_5(t_data *d, int *tmp_count, int j)
{
	(*tmp_count) += ft_tri_insertion(d, j);
}

void			ft_len_100(t_data *d, int *tmp_count, int j)
{
	(*tmp_count) += ft_tri_insertion(d, j);
	(*tmp_count) += ft_tri_insertion_b(d, 1);
}

void			ft_incrementation_j(t_data *d, int *j)
{
	if (d->len_a > 50 && d->len_a < 500)
		(*j) += 4;
	else if (d->len_a == 500)
		(*j) += 40;
	else
		(*j) += 1;
	if (*j == -1)
		(*j)++;
}

int				ft_get_solut_aux(t_data *d, int *j, t_stack *tmp)
{
	int			n;
	int			tmp_count;
	int			save_i;
	int			count;

	tmp_count = 0;
	count = 1000000;
	n = ft_get_nbr(d->a, d->b, 1);
	while (++(*j) < n)
	{
		tmp_count = 0;
		if (*j < 0)
			ft_len_100(d, &tmp_count, -(*j));
		else
			ft_len_100(d, &tmp_count, *j);
		if (tmp_count < count)
		{
			save_i = *j;
			count = tmp_count;
		}
		ft_free_copy(d, tmp);
		ft_incrementation_j(d, j);
	}
	return (save_i);
}

void			ft_get_solut(t_data *d)
{
	int			j;
	int			save_i;
	t_stack		*tmp;

	j = ft_get_nbr(d->a, d->b, 0);
	tmp = NULL;
	ft_copy_list(&tmp, d->a);
	if (j == -1)
		j--;
	save_i = ft_get_solut_aux(d, &j, tmp);
	ft_free_copy(d, tmp);
	d->input = 1;
	if (save_i < 0)
		save_i *= -1;
	ft_call_fcnt(d, save_i);
	ft_free_list(&tmp);
}
