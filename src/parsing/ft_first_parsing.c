#include "../../inc/asm.h"

/*
** cettte fonction ;
**       gere le fait que le fichier soit vide
**       extrait les commentaires dans une list de chars dans la structure de player
**       et le source dans une list de char dans la structure player
*/

void    ft_first_parsing(char *url_file, t_player *player)
{
	t_charlist      *file;
	char            *file_str;
	char            *ret;

	file = NULL;
	ft_is_good_format_param(url_file);
	if (!ft_read_url_file(url_file, &file))// chaneger null to exit
		return ; /// cas d'erruer probleme  de lecture fichier exit().....
	//      ft_is_there_forbiden_char(file);

	/*retourner dans file_str une string ou il ya tout le fichier concatener separer par des \n*/
	file_str = ft_prepare_file(file, SEP);
	ft_dell_list_charlist(&file);

	/* retourne un fichier sans comment */
	ret = ft_purification_file(file_str, &player->comment);
	ft_strdel(&file_str);

	/*  mettre le tout dans une lise de char ici **/
	player->file = ft_str_to_charlist(ret, '\n');
	ft_strdel(&ret);
}
