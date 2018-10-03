/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_info_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:13:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/03 14:16:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

/*
**	first passe :
**
**	in put
**	{
**		file	<A list of strings, each node contains a line of the file>
**		player	<The structure where we will store the data of the champion>
**		op_tab	<the table that contains the information about the instructions>
**	}
**
**	what the fonction do ??
**	this function extract information from the file and save them into
**	the player
**	this function do the syntaxique/semantique checking
**	output
**	{
**		a boolean to report that the function has successfully done his job
**		return True  if the function did all its work
**		return False if the file given is empty or null
**	}
*/

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
