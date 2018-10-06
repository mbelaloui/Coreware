/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_args_inst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:00:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/05 13:08:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

/*
**	in put
**	{
**		tab_args	<list of arguments in an instruction>
**		name_op		<the name of the instruction>
**		args		<string that contain all the arguments of the
**						instruction>
**		op			<the structure of that contain all the informaion
**						of an instruction>
**	}
**
**	what the fonction do ??
**	this function check if the arguments given in the tab_args are compatible
**		withe the instruction op->mnemonique
**		it will get the value corresponding to the argument of eatch argument
**		and look if the utilisation of the argument is possible
**
**	output
**	{
**		the instruction will return void
**		if the fonction detect an invalide param
**			it will exit the programme withe a code error
**	}
*/

void	ft_check_arg_asm(char **tab_args, char *name_op, char *args,
		t_op *op)
{
	int pos;
	int param;

	pos = 0;
	while (tab_args[pos])
	{
		if (!(param = ft_get_type_args(tab_args[pos], pos)))
			ft_error_args(ERROR_TYPE_ARG,
					name_op, args, tab_args[pos]);
		if (!(param & op->param))
			ft_error_args(ERROR_TYPE_ARG,
					name_op, args, tab_args[pos]);
		pos++;
	}
}
