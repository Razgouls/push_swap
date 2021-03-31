/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:58:30 by eoliveir          #+#    #+#             */
/*   Updated: 2021/03/31 08:14:08 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include "../libft/includes/libft.h"

typedef struct      s_stack
{
	int             nbr;
	struct s_stack	*prev;
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
t_stack			*ft_get_last_list(t_stack *s);
void			ft_copy_list(t_stack **dest, t_stack *src);
void			ft_free_list(t_stack **s);
int				ft_issorted(t_data *d, t_stack *a);
void			ft_delete_elem_first(t_data *d, t_stack **s, int id);
t_stack			*ft_new_elem(t_stack *next, t_stack *prev, int nbr);
void			ft_modif_elem(t_stack *cur, t_stack *next, t_stack *prev);
void			ft_add_front_list(t_data *d, int id, t_stack **s, int nbr);

void			ft_memdel(void *ptr);
int				ft_check_number(char *str);
void			ft_setup_len(t_data *d, int id, char op);

void			ft_print_stack(t_stack *s);
void			ft_print_stack_inv(t_stack *s);
void			ft_print_infos(t_data *d);

/*
** FILL_STACK
*/
int				ft_fill_stack(char **argv, t_data *d);
int				ft_is_not_integer(char *str);

/*
** OPERANDE_A
*/
void			ft_sa(t_data *d);
void			ft_pa(t_data *d);
void			ft_ra(t_data *d, int id, t_stack **s);
void			ft_rra(t_data *d, int id, t_stack **s);

/*
** OPERANDE_B
*/
void			ft_sb(t_data *d);
void			ft_pb(t_data *d);
void			ft_rb(t_data *d, int id, t_stack **s);
void			ft_rrb(t_data *d, int id, t_stack **s);

/*
** OPERANDE_S
*/
void			ft_ss(t_data *d);
void			ft_rr(t_data *d);
void			ft_rrr(t_data *d);

/*
** OPERANDE_SPEC
*/
void			ft_before_last(t_data *d);
void			ft_third_pos(t_data *d);

/*
** PUSH_SWAP
*/
int				ft_tri_insertion(t_data *d, int max);
int				ft_tri_insertion_b(t_data *d, int max);
void			ft_random_nbr(t_data *d, int n, int max);
int				ft_get_nbr(t_stack *s, t_data *d, int id);
int				ft_get_place(t_stack *s, int nbr, int id);

/*
** RADIX SORT
*/
int				ft_radix_sort(t_data *d);
void			ft_radix_sort_bis(int i);

/*
** SORT
*/
int				ft_small_len(t_data *d, int *cmp);
int				ft_small_len_a(t_data *d, int *cmp);
int				ft_small_len_b(t_data *d, int *cmp);
int				ft_small_len_b_bis(t_data *d, int *cmp);
int				ft_med_len(t_data *d, int *cmp);

/*
** NEW_ALGO
*/
void			ft_tri_three_long(t_data *d, int *cmp);
void			ft_divise_list(t_data *d, t_stack *s);
int				ft_quick_sort(t_data *d);

#endif