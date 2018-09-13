/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_good_format_param.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:09:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 16:20:35 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

/*
** voir ici avec le -o si ca pourrait engendrer des problemes
** si non extraire les donnes en ammont le nom du fichier in et out
**
** voir si ont ne peut pas faire une boucle est boucler sur charque ficheir
** avec ou sans flag -m multipul
**
** changer le retuen en BOOL
** return (T);
** return (F);
*/

void	ft_is_good_format_param(char *url_file)
{
	if (ft_isempty(url_file))
		ft_error_param(ERROR_NO_URL_FILE, url_file);
	if (ft_comptword(url_file, ' ') != 1)
		ft_error_param(ERROR_MULTIPUL_PARAM, url_file);
	else if (!ft_is_good_format_urlfile(url_file))
		ft_printf("{red}name file valide{eoc} KO\n", url_file);
	else
		ft_printf("Name file valide {green} OK {Eoc}\n"
				"reading file\n",
				url_file);
}
