/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:58:48 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 15:08:27 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_put_help(char *name, t_option *op)
{
	ft_printf("%s helper :\n\n"
	"\t -B : print the binary version of the source code.\n"
	"\t -d : show which of the opcodes needed a description oct.\n"
	"\t -D : print the decimal version of the source code.\n"
	"\t -e : make the compiler sensible for errors.\n"
	"\t -h : show this message.\n"
	"\t -H : print the hexa-decimal version of the source code.\n"
	"\t -m : to compile multiple sources file.\n"
	"\t -o : show description of op-codes.\n"
	"\t -p : Print a detailed description of the source file.\n"
	"\t -s : print symboles table.\n"
	"\t -S : show label size of op-code.\n"
	"\t -t : show informations about type of each op-code.\n"
	"\t -u : print usage.\n"
		"", name + 2);
	ft_put_usage(name, op);
}
