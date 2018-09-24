/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_opr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:23:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/22 13:32:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_manage_opr(int opr, t_int_list **inst_src_list)
{
	if (opr < 17 && opr > 0)
		ft_add_end_intlist( opr, inst_src_list);
	else
		ft_error_reading_file(ERROR_FORMAT_FILE);
	return (1);
}
