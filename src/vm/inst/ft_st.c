/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:43 by mint              #+#    #+#             */
/*   Updated: 2018/10/12 17:31:39 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/12 15:54:56 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

void	put_process(t_process *process)
{
	int pt;

	ft_printf("\n-------------------------------------\n");
	ft_printf("id_parent process id {green}%d{eoc}",process->id_parent);
	ft_printf("pc = %d{eoc}\n", process->pc);
	pt = -1;
	while (++pt < REG_NUMBER)
		ft_printf("reg [%d] = %d\n",pt + 1, process->reg[pt]);
	process = process->next;
	ft_printf("\n-------------------------------------\n");
}

BOOL	ft_st(t_vm *vm, t_process *process)
{
//	t_op	*op_tab[NBR_OP];
	unsigned int val;
	put_process(process);

ft_printf("param 1 = %d", process->curent_instruction.vale_arg[0]);

if (process->curent_instruction.vale_arg[0])
	process->carry = 0;
else
	process->carry = 1;
val = process->reg[process->curent_instruction.vale_arg[0] - 1];
if (process->curent_instruction.type_arg[1] == REG_CODE) //valeur a verifer aller dans la meme fonction pour tester si regNUm n'est pas superieur a ce qui est fixer
	process->reg[process->curent_instruction.vale_arg[1]] = val;
else
{
	ft_printf("\n-------------------------------------\n");
	ft_printf("\n-------------------------------------\n");
	ft_printf("\n-------------------------------------\n");
	ft_printf("\n-------------------------------------\n");
	ft_printf("\n-----------val = %hhd------------\n", val);

	unsigned char * tab = ft_int_to_byts((unsigned)val, DIR_SIZE);
	int pt = -1;
	while (++pt < DIR_SIZE)
	{
			ft_printf("\n--------------%.2x-------------------\n", tab[pt]);
		vm->mem[process->curent_instruction.vale_arg[1] + pt + process->pc - DIR_SIZE % MEM_SIZE][MEM_SRC] = tab[pt];//process->curent_instruction.vale_arg[0] % MEM_SIZE;
		vm->mem[process->curent_instruction.vale_arg[1] + pt + process->pc - DIR_SIZE % MEM_SIZE][MEM_DESC] = process->id_parent;//process->curent_instruction.vale_arg[0] % MEM_SIZE;
	}
}

put_process(process);

//	ft_get_op_tab(op_tab);
//	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
//	ft_free_optab(op_tab);
	return (T);
}
/*




BOOL	ft_st(t_vm *vm, t_process *process)
{
//	t_op	*op_tab[NBR_OP];
	int val;

	val = process->curent_instruction.vale_arg[0];
	if (process->curent_instruction.vale_arg[0])
		process->carry = 1;
	else
		process->carry = 0;

	if (process->curent_instruction.type_arg[1] == REG_CODE) //valeur a verifer aller dans la meme fonction pour tester si regNUm n'est pas superieur a ce qui est fixer
		process->reg[process->curent_instruction.vale_arg[1]] = val;
	else
	{
		vm->mem[(process->pc + val) % MEM_SIZE][MEM_SRC] = val;
//		vm->mem[(process->pc + val) % MEM_SIZE][MEM_SRC] = val;// colorer les cases meme en fonction de l'id du process 
	}	
//	ft_get_op_tab(op_tab);
//	ft_put_opr_exe(&(process->curent_instruction), op_tab);
//	(void) vm;
//	ft_free_optab(op_tab);
	return (T);
}
*/