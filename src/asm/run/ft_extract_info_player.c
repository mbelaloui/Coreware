/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_info_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:13:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/16 14:03:44 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

BOOL	ft_extract_info_player(t_charlist *file, t_player *player,
		t_op *op_tab[NBR_OP])
{
	t_charlist	*sc;
	char		*str_file;
	char		*str;
	int			pt;

	if (!(str_file = ft_charlist_to_str(file, SEP)))
		return (F);
	pt = ft_extraire_head_info(str_file, player);
	str = ft_format_str(str_file + pt);
	ft_strdel(&str_file);
	sc = ft_str_to_format_charlist(str, SEP);
	ft_extraire_source(sc, player, op_tab);
	ft_dell_list_charlist(&sc);
	ft_strdel(&str);
	return (T);
}
