/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:31:00 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/18 08:31:02 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int cmp;

	cmp = 0;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		cmp++;
		lst = lst->next;
	}
	return (cmp + 1);
}
