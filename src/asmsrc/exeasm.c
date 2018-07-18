/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:02:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 19:31:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**faire une foncion format just pour corware qui remplace les espaces par des
** /t just pour faire jolie
 */


#include "../../inc/op.h"

/*
** retravailler les operations de ramplassement de \n par des ~ sur tout dans
** le cas des " "
**
*/

void	run(char *url_file,t_player *player)
{
	//	player->comment = NULL;

	ft_first_parsing(url_file, player);
	if (!player->file)
	{
		ft_printf("empty file\n");
		exit(0);
	}
	ft_get_head_comment(player);
	//	   ft_get_basic_comment(file, player);
/*	ft_put_list_charlist(player->file);
	ft_printf("{eoc}****************comment ********************\n{yellow}");
	ft_put_list_charlist(player->comment);
	ft_printf("{eoc}");
*/
}

int		main(int argc, char **argv)
{
	unsigned long	op;
	char			*param;
	int				pt;
	t_player		player;


	ft_bzero(&player, sizeof(player));
	op = 0;
	param = ft_mat_to_str(argv, 1);
	pt = ft_extract_options(param, &op, ft_is_option, ft_set_options);
	/*
	   faire attention a l'option {-o + output } si non l'enlever carrement
	   si non mettre un nom par defaut s'il ya pas un nom valide 
	   s\il ya directement une url d'un fichier valide
	   */
	if (pt < 0)
		ft_error_param(ERROR_BAD_PARAM, param);
	else if (argc == 1)
		ft_error_param(ERROR_NO_PARAM, param);
	else
		run(param + pt, &player);

	//ne pas oublier de free param
	ft_dell_list_charlist(&player.comment);
	ft_dell_list_charlist(&player.file);
	ft_strdel(&param);
	return (0);
}
