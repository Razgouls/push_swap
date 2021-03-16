/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:08:04 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/17 16:08:05 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp_nbr;

	if (n < 0)
	{
		write(fd, "-", 1);
		tmp_nbr = n * -1;
	}
	else
		tmp_nbr = n;
	if (tmp_nbr > 9)
		ft_putnbr_fd(tmp_nbr / 10, fd);
	ft_putchar_fd(tmp_nbr % 10 + '0', fd);
}
