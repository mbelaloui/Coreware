/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_warning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:28:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 16:52:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	ft_warning(int id_warn, int size, char *data, t_option *op)
{
	if (op->d || op->o || op->p || op->t || op->y)
		return ;
	if (op->e)
	{
		if (id_warn == WARNING_SIZE_CHAMP)
			ft_printf("{red}Error{eoc} champion size %d,"
					" it should be less than %d\n", size, CHAMP_MAX_SIZE);
		else if (id_warn == WARNING_DOUBLE_DEF_LAB)
			ft_printf("{red}Error{eoc} double declaration of"
					" label %s\n", data);
		else if (id_warn == WARNING_UNUSED_LAB)
			ft_printf("{red}Error{eoc} label [%s]"
					" declared but not used\n", data);
		exit(id_warn);
	}
	if (id_warn == WARNING_SIZE_CHAMP)
		ft_printf("{yellow}Warning{eoc} champion size %d,"
				" it should be less than %d\n", size, CHAMP_MAX_SIZE);
	else if (id_warn == WARNING_DOUBLE_DEF_LAB)
		ft_printf("{yellow}Warning{eoc} double declaration of"
				" label %s\n", data);
	else if (id_warn == WARNING_UNUSED_LAB)
		ft_printf("{yellow}Warning{eoc} label [%s]"
				" declared but not used\n", data);
}
