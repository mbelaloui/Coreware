/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_basic_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:07:14 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 15:29:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

// faire en sorte de detecter le pasage du head au src pour laisser un espace

static t_charlist	*clear_file(t_charlist **file)
{
	t_charlist	*temp_list;
	t_charlist	*sauv_temp_list;
	char		*temp;
	int			cp_line;

	cp_line = 0;
	temp_list = NULL;
	ft_cp_list_charlist(*file, &temp_list);
	ft_dell_list_charlist(file);
	sauv_temp_list = temp_list;
	while (temp_list)
	{
		temp = ft_format_str(temp_list->data);
		if (ft_strlen(temp) || cp_line < 3)
			ft_add_charlist(temp, file);
		ft_strdel(&temp);
		temp_list = temp_list->next;
		cp_line++;
	}
	ft_dell_list_charlist(&sauv_temp_list);
	return (*file);
}

/*
** regler sgf dans ml comment sur une seul ligne
*/

void				ft_get_basic_comment(t_charlist *file, t_player *player)
{
	t_charlist	*comment;
	t_charlist	*ret_file;
	int			index;

	comment = NULL;
	ret_file = NULL;
	while (file)
	{
		if ((index = ft_get_start_basic_comment(file->data)) > -1)
			ft_split_sources(index, file, &comment, &ret_file);
		else if ((index = ft_get_start_advanced_comment(file->data)) > -1)
			ft_split_adv_sources(index, file, &comment, &ret_file);
		else if ((index = ft_get_start_ml_comment(file->data)) > -1)
		{
			ft_printf("allez dans le fichier ft_get_basic_comment pour"
					" comprendre .... \nciao\n");
			exit(0);
	/*
	 * pour l'instant le proramme ne prend pas en compt les comment multie lignes
	 * pour prendre en compt quelques cas il faut decommanter cette ligne 
	 * file = ft_manage_advenced_comment(file, &comment, &ret_file);
	 * 
	 * 
	 * mettre tout dans une chaine de caratctere 
	 * voir si on a jamais de '~' si oui file invalide 
	 * faire des strjoin entre chaque ligne et mettres des '~' entre chaque line
	 * faire le traitement des commentaires entre chaque starte de comment et '~'
	 * mettre a chaque fois la ligne du debut jusqu'a '~' dans un t_charlist
	 * continuer le traitement
	 *
	 * pour le head sur plusieurs ligne ne pas mettre de '~' entre les ligne 
	 * quand c'est pas la fin de la donnee
	 * ex : .name " voila 
	 *	il n'y aura pas de '~' entre cette ligne et la premiere no la prochainne
	 *	line 3 nom	 ici ajouter le delimiteur"~.comment "meme 
	 *	chose pour ici aussi comme dans name"
	 *
	 * */
		}
		else
			ft_add_charlist(file->data, &ret_file);
		file = file->next;
	}
	ft_cp_list_charlist(ret_file, &player->file);
	ft_dell_list_charlist(&ret_file);
	ft_cp_list_charlist(comment, &player->comment);
	ft_dell_list_charlist(&comment);
	clear_file(&player->file);
}
