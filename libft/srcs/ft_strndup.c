/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:16:28 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/08 15:16:41 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int length)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = (char*)malloc((length + 1) * sizeof(char))) != NULL)
	{
		while (src[i] && i < length)
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
	}
	else
		return (NULL);
	return (str);
}
