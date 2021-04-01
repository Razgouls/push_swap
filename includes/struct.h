/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 09:59:36 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 11:01:30 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_data
{
	t_stack			*a;
	t_stack			*b;
	int				len_a;
	int				len_b;
	int				input;
}					t_data;

#endif
