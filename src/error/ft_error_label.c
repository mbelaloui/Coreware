/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:21:15 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 15:13:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_error_label(int error, char *label, char c, char *str)
{
	if (error == ERROR_END_CHAR_LABEL)
		ft_printf("{red}Error{eoc} char end of label expected <%s%c>\n"
				"found <%s>\n", label, LABEL_CHAR, str);
	else if (error == ERROR_FORMAT_LABEL)
		ft_printf("{red}Error{eoc} format label expected <%s%c>\n"
				"found <%s%c>\nno end char label <%c> found\n"
				, label, LABEL_CHAR, label, c, LABEL_CHAR);
	else if (error == ERROR_FORMAT_LABEL_ARG)
		ft_printf("{red}Error{eoc} format label arg\n");
	else if (error == ERROR_LABEL_NOT_DECLARED)
		ft_printf("{red}Error{eoc} label %s used but not"
				" declared\n", label);
	else
		ft_printf("{red}Error{eoc} label\n");
	exit(error);
}
