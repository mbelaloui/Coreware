/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:45:49 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 19:52:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

/*
** cettte fonction ;
**       gere le fait que le fichier soit vide
**       extrait les commentaires dans une list de chars dans la structure
**       de player
**       et le source dans une list de char dans la structure player
**
** chaneger null to exit
**			/// cas d'erruer probleme  de lecture fichier exit().....
*/

void	ft_first_parsing(char *url_file, t_player *player)
{
	t_charlist	*file;
	char		*file_str;
	char		*ret;

	file = NULL;
	ft_is_good_format_param(url_file);
	if (!ft_read_url_file(url_file, &file))
		return ;
	file_str = ft_prepare_file(file, SEP); // voir si il ya un char de comment et apres il ya un " avant la fin de la line laisser lesaer de linge
	ft_dell_list_charlist(&file);
	ret = ft_purification_file(file_str, &player->comment);
	ft_strdel(&file_str);
	player->file = ft_str_to_charlist(ret, '\n');
	ft_strdel(&ret);
}
