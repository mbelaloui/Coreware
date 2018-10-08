/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_op_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:11:52 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 14:17:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_handle_op_n(char **tab, t_url_file **champ)
{
	int		num;
	char	*url;

	if (tab[0])
	{
		num = ft_get_value_op(tab[0]);
		if (ft_existe_num(num, *champ))
			ft_error_param_vm(ERROR_ID_CHAMP, " ");
		url = ft_get_url(tab + 1);
		ft_add_urlfilelist(num, url, champ);
	}
	else
		ft_error_param_vm(ERROR_NO_PARAM_ID, " ");
	return (2);
}
