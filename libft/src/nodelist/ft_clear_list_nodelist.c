/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list_nodelist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:37:29 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/08 18:38:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

BOOL	ft_clear_list_nodelist(t_nodelist **list)
{
	if (list && *list)
	{
		while (*list)
			ft_dell_bgn_nodelist(list);
		return (T);
	}
	return (F);
}
