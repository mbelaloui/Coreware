/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_param_vm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:44:35 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 14:27:59 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_error_param_vm(int error, char *param)
{
	ft_printf("{red}Error{eoc} parameters arguments : ");
	if (ERROR_NO_PARAM == error)
		ft_printf("the program need parameters\n");
	else if (ERROR_WRONG_OPTION == error)
		ft_printf("unknown argument [%c].\n", param[0]);
	else if (ERROR_NO_SRC_FILE == error)
		ft_printf("ther's no .cor file.\n");
	else if (ERROR_NO_PARAM_ID == error)
		ft_printf("bad format param.\n");
	else if (ERROR_ID_CHAMP == error)
		ft_printf("duplicated id champ.\n");
	else if (ERROR_BAD_NBR_FILE == error)
		ft_printf("the number of champions can't be superior to 4.\n");
	else if (ERROR_NO_FILE == error)
		ft_printf("ther's a probleme with the url file {%s}.\n", param);
	else
		ft_printf("error id %d\n", error);
	ft_put_usage_vm();
	exit(error);
}
