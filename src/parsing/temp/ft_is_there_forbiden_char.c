/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_there_forbiden_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:50:48 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 13:51:01 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

/*
** faires des messages d'erreur plus propre
*/

void	ft_is_there_forbiden_char(t_charlist *file)
{
	char *to_del;

	to_del = ft_charlist_to_str(file, ' ');
	if (ft_isempty(to_del))
	{
		ft_printf("empty file");
		exit(0);
	}
	if (ft_is_c_in_str(SEP, to_del))
	{
		ft_printf("~ in the file");
		exit(0);
	}
	ft_strdel(&to_del);
}
