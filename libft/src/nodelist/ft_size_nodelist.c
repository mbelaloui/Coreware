/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_nodelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:05:37 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/18 15:06:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

int		ft_size_nodelist(t_nodelist *listnode)
{
	int ret;

	ret = 0;
	while (listnode)
	{
		ret++;
		listnode = listnode->next;
	}
	return (ret);
}
