/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:15:02 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 11:16:54 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"

void			ft_init_data(t_data *d)
{
	d->input = 0;
	d->len_a = 0;
	d->len_b = 0;
	d->a = NULL;
	d->b = NULL;
}

int				ft_is_not_integer(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len < 10)
		return (0);
	if (len > 11)
		return (-1);
	if (len == 10)
		return (ft_check_number(str));
	if (len == 11)
		return (ft_check_number_neg(str));
	return (0);
}

int				ft_isdoublon(int nbr, t_stack *s)
{
	while (s)
	{
		if (s->nbr == nbr)
			return (1);
		s = s->next;
	}
	return (0);
}

int				ft_fill_stack(char **argv, t_data *d)
{
	int		nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (nbr == 0 && ft_strcmp(argv[i], "0"))
			return (-1);
		if (ft_isdoublon(nbr, d->a))
			return (-1);
		if (ft_is_not_integer(argv[i]) == -1)
			return (-1);
		ft_add_back_list(d, 0, &d->a, nbr);
		i++;
	}
	return (0);
}
