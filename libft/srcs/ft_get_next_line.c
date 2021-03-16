/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elieoliveira <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:09:53 by elieolive         #+#    #+#             */
/*   Updated: 2020/12/02 11:03:12 by elieolive        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*save_rest(char *stock)
{
	int i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (stock + i);
		else if (stock[i + 1] == '\0')
			return (stock + i);
		i++;
	}
	return (0);
}

static int		ft_check(char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_check_line(char **stock, char **line, int res_read)
{
	char	*tmp;
	char	*tmp_bis;

	if (res_read < 0)
		return (-1);
	if (*stock && (tmp = save_rest(*stock)))
	{
		if (tmp[0] == '\n' && tmp[1])
		{
			*line = ft_strndup(*stock, ft_strlen(*stock) - ft_strlen(tmp));
			tmp_bis = ft_strndup(tmp + 1, ft_strlen(tmp + 1));
			free(*stock);
			*stock = tmp_bis;
			return (1);
		}
		else
			*line = ft_strndup(*stock, ft_strlen(*stock));
		free(*stock);
		*stock = NULL;
		return (1);
	}
	*line = 0;
	return (0);
}

int				ft_get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*stock[256];
	int				res_read;
	char			*tmp_stock;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL ||
		(!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char)))))
		return (-1);
	while ((res_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[res_read] = '\0';
		if (!stock[fd])
			stock[fd] = ft_strndup(buffer, ft_strlen(buffer));
		else
		{
			tmp_stock = ft_strjoin(stock[fd], buffer);
			free(stock[fd]);
			stock[fd] = tmp_stock;
		}
		if (ft_check(stock[fd]))
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (ft_check_line(&stock[fd], line, res_read));
}
