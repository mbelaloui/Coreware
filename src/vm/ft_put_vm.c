/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:55:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/06 11:08:27 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	ft_put_vm(t_vm *vm)
{
	ft_printf("/ ------------------------------------------------------ \\\n");
	ft_printf("                desciption vm \n");
	ft_printf("/ ------------------------------------------------------ \\\n");
	ft_printf("\tnbr_champ                       [%d]\n", vm->nbr_champ);
	if (vm->dump < 0)
		ft_printf("\tthe memory will not be dumped\n");
	else
		ft_printf("\tdump memory at :                [%d]\n", vm->dump);
	ft_printf("/ ------------------------------------------------------ \\\n");
	ft_printf("/ ---------- printing descption of champions ----------- \\\n");
	ft_put_listchamp(vm->champs);
	ft_printf("/ ------------------------------------------------------ \\\n");
}
