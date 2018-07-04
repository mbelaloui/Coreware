/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:09:57 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/04 21:26:14 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

void	ft_get_op_tab(t_op *op_tab[17])
{
	ft_init_op_tab(op_tab);
	ft_set_param(op_tab);
}


int		main(void)
{
	t_op *op_tab[17];
	
	ft_get_op_tab(op_tab);
	ft_put_op(op_tab);
	ft_put_typ_param(op_tab);
	return (0);
}


/*
**int		main(void)
**{
**	t_op *op_tab[17];
**	ft_get_op_tab(op_tab);
**		ft_put_op(op_tab);
**	ft_put_typ_param(op_tab);
**  voila pour is type ok
**il suffit de lui en voyer la description de op et le type de parame detecter
**	ft_printf(" hellow %d \n", ft_is_type_ok(op_tab[1], T_REG_P1));
**	return (0);
**}
*/
