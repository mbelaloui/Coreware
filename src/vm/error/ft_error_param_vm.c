/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_param_vm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:44:35 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/24 20:45:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../inc/vm.h"

void	ft_error_param_vm(int error, char *param)
{
	ft_printf("{red}Error{eoc} parameters arguments : \n");
	if (ERROR_NO_PARAM == error)
		ft_printf("the program need parameters\n");
	else if (ERROR_WRONG_OPTION == error)
		ft_printf("unknown argument [%c].\n", param[0]);
	else if (ERROR_BAD_PARAM == error)
		ft_printf("voila voila .\n", param);
	
//	if (ERROR_NO_PARAM_DUMP == error)
//		ft_printf("usage_dump.\n", param); //ft_usage_dump();
//	else
		ft_put_usage_vm();
//	else
//		ft_printf("{red}Error param{eoc} : %d\n", error);
	exit(error);
}
