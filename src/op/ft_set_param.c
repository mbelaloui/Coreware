/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:11:27 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/07 19:37:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

void	ft_set_param(t_op *op_tab[17])
{
	op_tab[0]->param = 0;
	op_tab[1]->param = T_DIR_P1;
	op_tab[2]->param = T_DIR_P1 | T_IND_P1 | T_REG_P2;
	op_tab[3]->param = T_REG_P1 | T_IND_P2 | T_REG_P2;
	op_tab[4]->param = T_REG_P1 | T_REG_P2 | T_REG_P3;
	op_tab[5]->param = T_REG_P1 | T_REG_P2 | T_REG_P3;
	op_tab[6]->param = T_REG_P1 | T_DIR_P1 | T_IND_P1 | T_REG_P2 | T_IND_P2
		| T_DIR_P2 | T_REG_P3;
	op_tab[7]->param = T_REG_P1 | T_IND_P1 | T_DIR_P1 | T_REG_P2 | T_IND_P2
		| T_DIR_P2 | T_REG_P3;
	op_tab[8]->param = T_REG_P1 | T_IND_P1 | T_DIR_P1 | T_REG_P2 | T_IND_P2
		| T_DIR_P2 | T_REG_P3;
	op_tab[9]->param = T_DIR_P1;
	op_tab[10]->param = T_REG_P1 | T_DIR_P1 | T_IND_P1 | T_DIR_P2 | T_REG_P2
		| T_REG_P3;
	op_tab[11]->param = T_REG_P1 | T_REG_P2 | T_DIR_P2 | T_IND_P2 | T_DIR_P3
		| T_REG_P3;
	op_tab[12]->param = T_DIR_P1;
	op_tab[13]->param = T_DIR_P1 | T_IND_P1 | T_REG_P2;
	op_tab[14]->param = T_REG_P1 | T_DIR_P1 | T_IND_P1 | T_DIR_P2 | T_REG_P2
		| T_REG_P3;
	op_tab[15]->param = T_DIR_P1;
	op_tab[16]->param = T_REG_P1;
}
