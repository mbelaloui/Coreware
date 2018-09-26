/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:01:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 18:59:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_get_value_op(char *str)
{
	char	*tmp;
	int		nb;

	if ((nb = ft_atoi_v3(str)) < 0)
		ft_error_param_vm(ERROR_NO_PARAM_ARG, " ");
	if (!(tmp = ft_itoa(nb)))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	if ((ft_strcmp(tmp, str) != 0))
		ft_error_param_vm(ERROR_NO_PARAM_ARG, " ");
	free(tmp);
	return (nb);
}
