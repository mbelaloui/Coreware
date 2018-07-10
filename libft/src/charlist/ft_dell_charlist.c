/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_charlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:34:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/10 17:11:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

BOOL	ft_dell_charlist(t_charlist **to_free)
{
	if (to_free)
	{
		ft_strdel(&(*to_free)->data);
		free(*to_free);
		*to_free = NULL;
		return (T);
	}
	return (F);
}
