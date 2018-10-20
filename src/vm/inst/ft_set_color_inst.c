/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color_inst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:55:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:56:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_set_color_inst(t_vm *vm, int start, int len, int id_process)
{
	while (len)
	{
		vm->mem[start][MEM_DESC] = id_process + ACTUAL_ACTION;
		len--;
		start++;
	}
}
