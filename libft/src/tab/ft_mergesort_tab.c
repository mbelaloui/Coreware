/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:11:42 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/02 11:10:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tab.h"

/*
**void	merge_tab_d(intmax_t *tab,  int mid, int size)
**{
**	intmax_t	*temp;
**	int			pt_l;
**	int			pt_r;
**	int			pt;
**
**	temp = malloc (sizeof(intmax_t) * size);
**	pt_l = 0;
**	pt = 0;
**	pt_r = mid ;
**	ft_printf("size  = %d\n", size);
**	while (pt_l < mid && pt_r < size)
**	{
**		ft_printf("tab[%d] =  %d\t tab[%d] = %d\t ",pt_l,
**tab[pt_l],pt_r, tab[pt_r]);
**		if (tab[pt_l] > tab[pt_r])
**			temp[pt++] = tab[pt_r++];
**		else
**			temp[pt++] = tab[pt_l++];
**		ft_printf("temp[%d] = %d \n", pt -1 , temp[pt - 1]);
**	}
**	fill_tab_int(temp + pt, tab + pt_l, mid - pt_l );
**	fill_tab_int(temp + pt + pt_l - mid, tab + pt_r, size - pt_r);
**	ft_printf("temp[%d] = %d \n", pt - 1 , temp[pt - 1 ]);
**	ft_put_intmax_tab(tab, size * sizeof(intmax_t));
**	while (size--)
**		tab[size] =  temp[size];
**	free(temp);
**	ft_printf("\n--------------------------------------\n");
**}
*/

static void	fill_tab_int(intmax_t *dest, intmax_t *src, int size)
{
	int pt;

	pt = 0;
	while (size--)
	{
		dest[pt] = src[pt];
		pt++;
	}
}

static void	merge_tab(intmax_t *tab, int mid, int size)
{
	intmax_t	*temp;
	int			pt_l;
	int			pt_r;
	int			pt;

	temp = malloc(sizeof(intmax_t) * size);
	pt = 0;
	pt_l = 0;
	pt_r = mid;
	while (pt_l < mid && pt_r < size)
	{
		if (tab[pt_l] > tab[pt_r])
			temp[pt++] = tab[pt_r++];
		else
			temp[pt++] = tab[pt_l++];
	}
	fill_tab_int(temp + pt, tab + pt_l, mid - pt_l);
	fill_tab_int(temp + pt + pt_l - mid, tab + pt_r, size - pt_r);
	while (size--)
		tab[size] = temp[size];
	free(temp);
}

void		ft_mergesort_tab(intmax_t *tab, int r)
{
	int mid;

	if (r > 1)
	{
		mid = r / 2;
		ft_mergesort_tab(tab, mid);
		ft_mergesort_tab(tab + mid, r - mid);
		merge_tab(tab, mid, r);
	}
}
