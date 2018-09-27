/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_url.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:57:59 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 19:58:19 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

char	*ft_get_url(char **tab)
{
	if (tab[0])
	{
		if (ft_manage_vm_url(tab[0]))
			return (tab[0]);
		else
			ft_error_param_vm(ERROR_NO_PARAM_ID, " ");
	}
	else
		ft_error_param_vm(ERROR_NO_PARAM_ID, " ");
	return (NULL);
}
