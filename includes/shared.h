/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:50:19 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 10:00:07 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include "../libft/includes/libft.h"

#include "struct.h"

/*
** FT_FILL_STACK
*/
void				ft_init_data(t_data *d);
int					ft_is_not_integer(char *str);
int					ft_isdoublon(int nbr, t_stack *s);
int					ft_fill_stack(char **argv, t_data *d);

/*
** OPERANDE_A
*/
void				ft_sa(t_data *d);
void				ft_pa(t_data *d);
void				ft_ra(t_data *d, int id, t_stack **s);
void				ft_rra(t_data *d, int id, t_stack **s);

/*
** OPERANDE_B
*/
void				ft_sb(t_data *d);
void				ft_pb(t_data *d);
void				ft_rb(t_data *d, int id, t_stack **s);
void				ft_rrb(t_data *d, int id, t_stack **s);

/*
** OPERANDE_S
*/
void				ft_ss(t_data *d);
void				ft_rr(t_data *d);
void				ft_rrr(t_data *d);

/*
**	FT_LIST
*/
void			ft_free_list(t_stack **s);
t_stack			*ft_get_last_list(t_stack *s);
t_stack			*ft_new_elem(t_stack *next, t_stack *prev, int nbr);
int				ft_issorted(t_data *d, t_stack *a);
void			ft_free_copy(t_data *d, t_stack *tmp);
void			ft_add_front_list(t_data *d, int id, t_stack **s, int nbr);
void			ft_add_back_list(t_data *d, int id, t_stack **s, int nbr);
void			ft_add_back_list_bis(t_stack **s, int nbr);
void			ft_copy_list(t_stack **dest, t_stack *src);
void			ft_delete_elem_first(t_data *d, t_stack **s, int id);

/*
** FT_UTILS
*/
void			ft_setup_len(t_data *d, int id, char op);
void			ft_memdel(void *ptr);
int				ft_check_number(char *str);
void			ft_print_stack(t_stack *s);

#endif
