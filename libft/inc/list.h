/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:45:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/19 12:32:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "libft.h"

typedef struct			s_int_list
{
	intmax_t			data;
	struct s_int_list	*next;
}						t_int_list;

BOOL					ft_add_bgn_intlist(intmax_t nbr, t_int_list**list);
BOOL					ft_add_end_intlist(intmax_t nbr, t_int_list **list);
BOOL					ft_add_elem_intlist(int index, intmax_t nbr,
		t_int_list **list);
BOOL					ft_avg_intlist(const t_int_list *list,
		long double *avg);
void					ft_bubble_sort_int_list(t_int_list **list);
BOOL					ft_clear_intlist(t_int_list **list);
BOOL					ft_dell_bgn_intlist(t_int_list**list);
BOOL					ft_dell_elem_intlist(intmax_t nbr, t_int_list **list);
BOOL					ft_dell_end_intlist(t_int_list **list);
BOOL					ft_dell_index_intlist(int index, t_int_list **list);
int						ft_get_nbr_found_elem_intlist(const intmax_t e,
		const t_int_list *list);
BOOL					ft_get_val_intlist(const t_int_list *list,
		const int index, intmax_t *data);
BOOL					ft_is_empty_intlist(const t_int_list *list);
BOOL					ft_is_in_intlist(const intmax_t e,
		const t_int_list *list);
BOOL					ft_is_sorted_asc_intlist(const t_int_list *list);
BOOL					ft_is_sorted_des_intlist(const t_int_list *list);

BOOL					ft_max_int_list(const t_int_list *list, intmax_t *max);
void					ft_mergesort_intlist(t_int_list **list, int size);
BOOL					ft_med_intlist(t_int_list *list, long double *med);
BOOL					ft_min_intlist(const t_int_list *list, intmax_t *min);
t_int_list				*ft_new_intlist(const intmax_t nbr);

BOOL					ft_shift_bottom_intlist(t_int_list **list);
BOOL					ft_intervert_head_intlist(t_int_list **list);
BOOL					ft_shift_top_intlist(t_int_list **list);

BOOL					ft_intervert_head_tow_intlist(t_int_list **list_a,
		t_int_list **list_b);
BOOL					ft_push_first_to_list(t_int_list **list_a,
		t_int_list **list_b);
BOOL					ft_shift_bottom_tow_intlist(t_int_list **list_a,
		t_int_list **list_b);
BOOL					ft_shift_top_tow_intlist(t_int_list **list_a,
		t_int_list **list_b);

size_t					ft_size_intlist(const t_int_list *list);
void					ft_put_intlist(const t_int_list *list);
void					ft_put_tow_piles(t_int_list *list_a,
		t_int_list *list_b);
t_int_list				*ft_tab_to_intlist(intmax_t *tab, size_t size);
int						ft_get_index_first_elem_bigger_intlist(
		const t_int_list *list, const intmax_t val);
int						ft_get_index_last_elem_bigger_intlist(
		const t_int_list *list, const intmax_t val);
int						ft_get_index_max_intlist(const t_int_list *list);
int						ft_get_index_min_intlist(const t_int_list *list);

BOOL					ft_get_pivot(t_int_list *list, int sizelist,
		intmax_t *ret, int pres);
intmax_t				*ft_intmax_list_to_tab(t_int_list *list);
void					ft_int_list_to_tab(intmax_t **dest, t_int_list *src,
		int size);
intmax_t				*ft_int_list_to_inttab(t_int_list *list);

BOOL					ft_are_cancel_out_action(char *action_a,
		char *action_b);

#endif
