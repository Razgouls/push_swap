/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:58:30 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/17 09:57:39 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../libft/includes/libft.h"

typedef struct      s_stack
{
	int             nbr;
	struct s_stack  *prev;
	struct s_stack  *next;
}                   t_stack;

typedef struct      s_data
{
	t_stack         *a;
	t_stack         *b;
	int             len_a;
	int             len_b;
}                   t_data;


/*
** UTILS
*/
void			ft_add_back_list(t_data *d, int id, t_stack **s, int nbr);
int				ft_size_list(t_stack *stack);
void			ft_free_list(t_stack **s);
void			ft_delete_elem_first(t_data *d, t_stack **s, int id);
t_stack			*ft_new_elem(t_stack *next, t_stack *prev, int nbr);
void			ft_add_front_list(t_data *d, int id, t_stack **s, int nbr);

void			ft_memdel(void *ptr);
int				ft_check_number(char *str);
void			ft_setup_len(t_data *d, int id, char op);

void			ft_print_stack(t_stack *s);

/*
** FILL_STACK
*/
int				ft_fill_stack(char **argv, t_data *d);
int				ft_is_not_integer(char *str);

/*
** OPERANDE_A
*/
void			ft_sa(t_data *d, t_stack **a);
void			ft_pa(t_data *d, t_stack **a, t_stack **b);
void			ft_ra(t_data *d, int id, t_stack **s);
void			ft_rra(t_data *d, int id, t_stack **s);

#endif