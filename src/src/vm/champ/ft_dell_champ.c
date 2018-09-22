/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:07:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/22 12:08:14 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_dell_champ(t_champ **champ)
{
	char	*name;
	char	*com;

	name = (*champ)->name;
	ft_strdel(&name);
	com = (*champ)->comment;
	ft_strdel(&com);
	//ft_dell_inst_src(&(*champ)->src);
	free(*champ);
}
