/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:52 by mint              #+#    #+#             */
/*   Updated: 2018/10/12 11:48:34 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** cette fonction va permettre de kill le process ou  le set as kill
**	a voir si on fait ca ici ou directement dans la fonction run_cycle/execution
**
** ************************************************************************* **
*/

BOOL	ft_null(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}
