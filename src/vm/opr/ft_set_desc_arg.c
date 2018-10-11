/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_desc_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:23:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/11 16:50:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

// verifier que la description des arguments par apport a l'operation
// est bien coherente

void	ft_set_desc_arg(int ocp, int nbr_param, t_opr_exe *opr_exe)
{
	int param;
	int desc;

	param = 0;
	while (param < nbr_param)
	{
		desc = (ocp & MASK_PARAM) >> 6;
		if (desc == REG_CODE)
			opr_exe->type_arg[param] = REG_CODE;
		else if (desc == IND_CODE)
			opr_exe->type_arg[param] = IND_CODE;
		else if (desc == DIR_CODE)
			opr_exe->type_arg[param] = DIR_CODE;
		ocp = ocp << 2;
		param++;
	}
}
