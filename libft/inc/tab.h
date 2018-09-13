/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:59:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/05 12:41:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

# include "libft.h"

BOOL		ft_avg_tab(const intmax_t *tab, long double *avg, int size);
void		ft_bubble_sort_tab(intmax_t *tab, size_t size);

long double	ft_med_tab(intmax_t *tab, size_t size);
void		ft_mergesort_tab(intmax_t *tab, int r);
void		ft_put_intmax_tab(intmax_t *tab, size_t size);

#endif
