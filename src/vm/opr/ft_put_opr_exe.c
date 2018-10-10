/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_opr_exe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:18:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 22:07:43 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static char	*get_name_type(int arg)
{
	if (arg == REG_CODE)
		return (ft_strdup("registre"));
	else if (arg == IND_CODE)
		return (ft_strdup("indirect"));
	else if (arg == DIR_CODE)
		return (ft_strdup("direct"));
	return (NULL);
}

static void	put_general_info(t_opr_exe *opr, t_op *op_tab[NBR_OP])
{
	char	*name;
	int		pt;

	pt = 0;
	ft_printf("operations [%s] type arg[", op_tab[opr->id_opr]->name);
	while (pt < op_tab[opr->id_opr]->nbr_param)
	{
		name = get_name_type(opr->type_arg[pt]);
		ft_printf("{green}%s{eoc}", name);
		ft_strdel(&name);
		pt++;
		if (pt < op_tab[opr->id_opr]->nbr_param)
			ft_printf(", ");
	}
}

static void	put_size_info(t_opr_exe *opr, t_op *op_tab[NBR_OP])
{
	int pt;

	pt = 0;
	while (pt < op_tab[opr->id_opr]->nbr_param)
	{
		ft_printf("{green}%d{eoc}", opr->size_arg[pt]);
		pt++;
		if (pt < op_tab[opr->id_opr]->nbr_param)
			ft_printf(", ");
	}
}

static void	put_value_info(t_opr_exe *opr, t_op *op_tab[NBR_OP])
{
	int pt;

	pt = 0;
	while (pt < op_tab[opr->id_opr]->nbr_param)
	{
		ft_printf("{green}%.2x{eoc}", (unsigned char)opr->vale_arg[pt]);
		pt++;
		if (pt < op_tab[opr->id_opr]->nbr_param)
			ft_printf(", ");
	}
}

void		ft_put_opr_exe(t_opr_exe *opr, t_op *op_tab[NBR_OP])
{
	put_general_info(opr, op_tab);
	ft_printf("] size [");
	put_size_info(opr, op_tab);
	ft_printf("] value [");
	put_value_info(opr, op_tab);
	ft_printf("]\n");
}
