/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_op_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:11:52 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 20:12:42 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_handle_op_n(char **tab, t_url_file **champ)
{
	int		id;
	char	*url;

	if (tab[0])
	{
		id = ft_get_value_op(tab[0]);
		if (ft_existe_id(id, *champ))
			ft_error_param_vm(ERROR_ID_CHAMP, " ");
		url = ft_get_url(tab + 1);
		ft_add_urlfilelist(id, url, champ);
	}
	else
		ft_error_param_vm(ERROR_NO_PARAM_ID, " ");
	return (2);
}
