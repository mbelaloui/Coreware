/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:52 by mint              #+#    #+#             */
/*   Updated: 2018/10/17 20:50:59 by mbelalou         ###   ########.fr       */
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
	ft_put_opr_exe(&(process->curent_instruction), vm->op_tab);
	(void) vm;
	return (T);
}
