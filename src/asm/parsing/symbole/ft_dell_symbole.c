/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_symbole.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:29:48 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 13:30:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

BOOL	ft_dell_symbole(t_symbole **to_free)
{
	if (to_free && *to_free)
	{
		ft_strdel(&(*to_free)->data);
		free(*to_free);
		*to_free = NULL;
		return (T);
	}
	return (F);
}
