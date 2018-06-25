/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_charlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:34:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/28 15:26:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

BOOL	ft_dell_charlist(t_charlist **to_free)
{
	if (to_free)
	{
		ft_strdel(&(*to_free)->data);
		free(*to_free);
		return (T);
	}
	return (F);
}
