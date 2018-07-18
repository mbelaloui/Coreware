/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:05:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 13:44:00 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

/*
** extraire les info utils de param
** print usage
*/

void		ft_error_param(int error, char *param)
{
	if (ERROR_NO_PARAM == error)
		ft_printf("{red}wrong nbr of params{eoc} %s\n");
	else if (ERROR_BAD_PARAM == error)
		ft_printf("{red}wrong param{eoc} : %s"
				" : option not reconized.\n", param);
	else if (ERROR_NO_URL_FILE == error)
		ft_printf("{red}wrong format param{eoc} : no url file found.\n");
	else if (ERROR_MULTIPUL_PARAM == error)
		ft_printf("{red}wrong format param{eoc} : %s"
				" : multipul sources file found.\n", param);
	else if (ERROR_WRONG_FORMAT_FILE == error)
		ft_printf("{red}wrong format file{eoc} : %s :"
				" the src file hase to be <*.s>.\n", param);
	exit(error);
}
