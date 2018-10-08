/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_id_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:13:20 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 14:18:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_url_file	*ft_get_id_champ(char **tab)
{
	t_url_file	*champ;
	char		*url;
	int			pt;
	int			num;

	pt = 0;
	champ = NULL;
	while (tab[pt])
	{
		if (ft_strcmp(tab[pt], "-n") == 0)
			pt += ft_handle_op_n(tab + pt + 1, &champ);
		else
		{
			num = ft_get_prev_num_urlfile(champ);
			if (ft_existe_num(num, champ))
				ft_error_param_vm(ERROR_ID_CHAMP, " ");
			url = ft_get_url(tab + pt);
			ft_add_urlfilelist(num, url, &champ);
		}
		pt++;
	}
	return (champ);
}
