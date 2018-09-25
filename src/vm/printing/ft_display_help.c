/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:57:37 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 19:51:15 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_display_help(void)
{
	ft_printf("%s helper :\n"
		"\t -v : run the program with a visualizator\n"
		"\t -a : allow you to put '.s' instead of '.cor' file and compile them"
		" directly with the asm program,\n\t the option '-a'"
		"must be the first parameters.\n"
		"\t\t usage: ./corewar [-a] [-vDnh] [champion1.s]\n"
		"\t -dump : dump the memory(hexa) after nbr_cycles.\n"
		"\t\t usage: ./corewar [-dump nbr_cycles] champion1.cor\n"
		"\t -n : allow to give a number to the next player\n"
		"\t\t usage : ./corewar [[-n number_champ] champion1.cor]\n"
		"", "vm" + 2);
}
