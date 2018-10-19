/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:53:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:57:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
**	run_vm :
**
**	in put
**	{
**	}
**
**	what the fonction do ??
**	this function extract information from the binary file and save them into
**		a list of champion
**	if all the champion <the reading/parsing step> are ok
**			w'll pass to the next step
**	else
**			w'll exit the program clear with an error message
**	NB : this function do the syntaxique/semantique checking
**	output
**	{
**		save the player information in the vm structure
**	}
*/

void	ft_init_vm(t_vm *vm, t_url_file *url_champ, t_vm_option op_vm)
{
	t_champ	*champ;
	int		fd;
	int		pos;

	if ((vm->nbr_champ = ft_size_url_champ(url_champ)) > 4)
		ft_error_param_vm(ERROR_BAD_NBR_FILE, " ");
	ft_get_op_tab(vm->op_tab);
	vm->dump = op_vm.d;
	pos = 1;
	while (url_champ)
	{
		if ((fd = ft_open_r_file(url_champ->url)) < 0)
			ft_error_param_vm(ERROR_NO_FILE, url_champ->url);
		champ = ft_read_champ_file(fd, url_champ->num, vm->op_tab, pos++);
		ft_add_bgn_champ(champ, &(vm->champs));
		url_champ = url_champ->next;
	}
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->check = 1;
	ft_init_tab_instruction(vm->action_instructions);
}
