/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:05:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/25 08:54:14 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

/*
** extraire les info utils de param
** print usage
*/

void		ft_error_param(int error, char *param)
{
	ft_printf("{red}Error{eoc} ");
	if (ERROR_NO_PARAM == error)
		ft_printf("The program need a file.s as param\n");
	else if (ERROR_MULTIPUL_PARAM == error)
		ft_printf("Wrong format param : %s : multipul params found.\n", param);
	else if (ERROR_WRONG_FORMAT_FILE == error)
		ft_printf("Wrong format file : %s : the src file hase to be <*.s>.\n",
		param);
	else
		ft_printf(": %d\n", error);
	exit(error);
}
