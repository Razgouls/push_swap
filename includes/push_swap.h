/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:46:21 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 09:44:49 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

/*
** FT_INSERTION
*/
int				ft_rotate_list(t_data *d, int id, int len, int place);
int				ft_tri_insertion(t_data *d, int max);
int				ft_tri_insertion_b(t_data *d, int max);

/*
** FT_PUSH_SWAP
*/
int				ft_call_fcnt(t_data *d, int j);

/*
** FT_SMALL_LEN
*/
void			ft_small_len(t_data *d);
void			ft_small_len_a(t_data *d);
void			ft_small_len_b(t_data *d);
void			ft_small_len_b_bis(t_data *d);

/*
** FT_SORT
*/
void			ft_len_5(t_data *d, int *tmp_count, int j);
void			ft_len_100(t_data *d, int *tmp_count, int j);
void			ft_incrementation_j(t_data *d, int *j);
int				ft_get_solut_aux(t_data *d, int *j, t_stack *tmp);
void			ft_get_solut(t_data *d);

/*
** FT_UTILS_PUSH_SWAP
*/
int				ft_get_inside(int nbr, t_stack *s);
int				ft_get_nbr(t_stack *s, t_stack *s2, int id);
int				ft_get_place(t_stack *s, int nbr, int id);
int				ft_get_best_place(t_stack *s, int n, int len);

#endif
