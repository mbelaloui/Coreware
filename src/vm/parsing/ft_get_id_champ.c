/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_id_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:13:20 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 14:35:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_url_file	*ft_get_id_champ(char **tab)
{
	t_url_file	*champ;
	char		*url;
	int			pt;
	int			id;

	pt = 0;
	champ = NULL;
	while (tab[pt])
	{
		if (ft_strcmp(tab[pt], "-n") == 0)
			pt += ft_handle_op_n(tab + pt + 1, &champ);
		else
		{
			id = ft_get_prev_id_urlfile(champ);
			if (ft_existe_id(id, champ))
				ft_error_param_vm(ERROR_ID_CHAMP, " ");
			url = ft_get_url(tab + pt);
			ft_add_urlfilelist(id, url, &champ);
		}
		pt++;
	}
	return (champ);
}
