/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:15:02 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/16 20:15:02 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int			ft_is_not_integer(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len < 10)
		return (0);
	if (len > 10)
		return (-1);
	if (ft_check_number(str) == -1)
		return (-1);
	return (0);
}

int			ft_isdoublon(int nbr, t_stack *s)
{
	while (s)
	{
		if (s->nbr == nbr)
			return (1);
		s = s->next;
	}
	return (0);
}

int			ft_fill_stack(char **argv, t_data *d)
{
	int		nbr;
	int		i;
	t_stack	*a;

	i = 0;
	a = NULL;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (nbr < 0 || (nbr == 0 && ft_strcmp(argv[i], "0")))
			return (-1);
		if (ft_isdoublon(nbr, a))
			return (-1);
		if (ft_is_not_integer(argv[i]) == -1)
			return (-1);
		ft_add_back_list(&a, nbr);
		i++;
	}
	d->a = a;
	return (0);
}