/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_intlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:32:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:32:35 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

t_int_list	*ft_tab_to_intlist(intmax_t *tab, size_t size)
{
	t_int_list	*list;
	size_t		pt;

	list = NULL;
	pt = 0;
	size /= sizeof(intmax_t);
	while (pt < size)
		ft_add_end_intlist(tab[pt++], &list);
	return (list);
}
