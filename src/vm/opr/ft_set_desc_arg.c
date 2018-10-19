/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_desc_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:23:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:22:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static int	get_id_pos_direct(int pos)
{
	if (pos == 1)
		return (T_DIR_P1);
	else if (pos == 2)
		return (T_DIR_P2);
	else
		return (T_DIR_P3);
}

static int	get_id_pos_indirect(int pos)
{
	if (pos == 1)
		return (T_IND_P1);
	else if (pos == 2)
		return (T_IND_P2);
	else
		return (T_IND_P3);
}

static int	get_id_pos_register(int pos)
{
	if (pos == 1)
		return (T_REG_P1);
	else if (pos == 2)
		return (T_REG_P2);
	else
		return (T_REG_P3);
}

int			get_desc_args(int code, int pos)
{
	pos++;
	if (code == REG_CODE)
		return (get_id_pos_register(pos));
	else if (code == IND_CODE)
		return (get_id_pos_indirect(pos));
	else if (code == DIR_CODE)
		return (get_id_pos_direct(pos));
	return (0);
}

void		ft_set_desc_arg(int ocp, int nbr_param, t_opr_exe *opr_exe)
{
	int param;
	int desc;

	param = 0;
	while (param < nbr_param)
	{
		desc = (ocp & MASK_PARAM) >> 6;
		if (desc == REG_CODE)
		{
			opr_exe->type_arg[param][TYPE_1] = get_desc_args(REG_CODE, param);
			opr_exe->type_arg[param][TYPE_2] = REG_CODE;
		}
		else if (desc == IND_CODE)
		{
			opr_exe->type_arg[param][TYPE_1] = get_desc_args(IND_CODE, param);
			opr_exe->type_arg[param][TYPE_2] = IND_CODE;
		}
		else if (desc == DIR_CODE)
		{
			opr_exe->type_arg[param][TYPE_1] = get_desc_args(DIR_CODE, param);
			opr_exe->type_arg[param][TYPE_2] = DIR_CODE;
		}
		ocp = ocp << 2;
		param++;
	}
}
