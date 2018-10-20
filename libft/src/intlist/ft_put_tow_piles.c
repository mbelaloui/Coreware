/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tow_piles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:55:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/30 19:20:32 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

static void	put_piles(t_int_list *l_a, t_int_list *l_b, int size_la,
		int size_lb)
{
	int cp;
	int max_size;

	max_size = ft_max(size_la, size_lb);
	cp = 0;
	while (cp < max_size)
	{
		ft_printf("\n");
		if (max_size - (size_la + cp) < 1)
		{
			ft_printf("%10ld\t", l_a->data);
			l_a = l_a->next;
		}
		else if (cp + 1 == max_size && !size_la)
			ft_printf("\t[∅]\t");
		else
			ft_printf("%10c\t", ' ');
		if (max_size - (size_lb + cp) < 1)
		{
			ft_printf("%10ld", l_b->data);
			l_b = l_b->next;
		}
		cp++;
	}
}

void		ft_put_tow_piles(t_int_list *l_a, t_int_list *l_b)
{
	int size_la;
	int size_lb;
	int max_size;

	size_la = ft_size_intlist(l_a);
	size_lb = ft_size_intlist(l_b);
	max_size = ft_max(size_la, size_lb);
	if (!max_size)
		ft_printf("\n\t[∅]\t\t[∅]");
	else
	{
		put_piles(l_a, l_b, size_la, size_lb);
		if (size_la == 0 && !max_size)
			ft_printf("\t[∅]\t");
		if (size_lb == 0)
			ft_printf("\t[∅]");
	}
	ft_printf("\n-----------------------------------\n %9A\t%10c\n", 'B');
}
