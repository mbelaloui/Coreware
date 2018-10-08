/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:21:15 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 09:01:10 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	ft_error_label(int error, char *label, char c, char *str)
{
	ft_printf("{red}Error{eoc} ");
	if (error == ERROR_END_CHAR_LABEL)
		ft_printf("Char end of label expected <%s%c>\n"
				"found <%s>\n", label, LABEL_CHAR, str);
	else if (error == ERROR_FORMAT_LABEL)
		ft_printf("Format label expected <%s%c>\n"
				"found <%s%c>\nno end char label <%c> found\n"
				, label, LABEL_CHAR, label, c, LABEL_CHAR);
	else if (error == ERROR_FORMAT_LABEL_ARG)
		ft_printf("Format label arg\n");
	else if (error == ERROR_LABEL_NOT_DECLARED)
		ft_printf("Label %s used but not declared\n", label);
	else if (ERROR_LABEL_EXPECTED_BUT_OPR_FOUND == error)
		ft_printf("A function name can not be used as a label [%s]", str);
	else
		ft_printf("{red}Error{eoc} label\n");
	exit(error);
}
