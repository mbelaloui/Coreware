/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_help_vm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:57:37 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:50:32 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_help_vm(void)
{
	ft_printf("{yellow}helper{eoc} :\n"
		"\t {green}-dump{eoc} : dump the memory(hexa) after nbr_cycles.\n"
		"\t {green}-h{eoc}    : show this message.\n"
		"\t {green}-g{eoc}    : run the program with a graphique mode.\n"
		"\t {green}-v{eoc}    : run the program with a verbos mode.\n");
	ft_put_usage_vm();
	exit(0);
}
