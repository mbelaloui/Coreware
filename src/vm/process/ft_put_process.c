/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:16:01 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 10:03:04 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_process(t_process *process)
{
	while (process)
	{
		ft_printf("%s ", (process->a_live) ? "process alive" : "process is dead");
		ft_printf("{green}live for champ num = %d \t id_parent  %d\t",
		process->reg[0], process->id_parent);
		ft_printf("add start %d{eoc}\n\t\t<--------------->\n", process->pc);
		process = process->next;
	}
}
