/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:30:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/11 17:10:27 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"


/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_live(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	process->nbr_live++;
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_ld(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_st(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_add(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_sub(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_and(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	ft_free_optab(op_tab);
	(void) vm;
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_or(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	ft_free_optab(op_tab);
	(void) vm;
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_xor(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	ft_free_optab(op_tab);
	(void) vm;
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_zjmp(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_ldi(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_sti(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_fork(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_lld(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_lldi(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_lfork(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_aff(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
** cette fonction va permettre de kill le process ou  le set as kill
**	a voir si on fait ca ici ou directement dans la fonction run_cycle/execution
**
** ************************************************************************* **
*/

BOOL	ft_null(t_vm *vm, t_process *process)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);
	return (T);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

void	init_tab_instruction(BOOL (*action_instructions[NBR_OP])(t_vm *vm, t_process *process))
{
	(void)(action_instructions);

	action_instructions[0] = &ft_null;
	action_instructions[1] = &ft_live;
	action_instructions[1] = &ft_live;
	action_instructions[2] = &ft_ld;
	action_instructions[3] = &ft_st;
	action_instructions[4] = &ft_add;
	action_instructions[5] = &ft_sub;
	action_instructions[6] = &ft_and;
	action_instructions[7] = &ft_or;
	action_instructions[8] = &ft_xor;
	action_instructions[9] = &ft_zjmp;
	action_instructions[10] = &ft_ldi;
	action_instructions[11] = &ft_sti;
	action_instructions[12] = &ft_fork;
	action_instructions[13] = &ft_lld;
	action_instructions[14] = &ft_lldi;
	action_instructions[15] = &ft_lfork;
	action_instructions[16] = &ft_aff;
}

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/


/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

void	ft_rest_color(t_vm *vm, t_process *list_process)
{
	int			start;

	if (list_process->a_live)
	{
		start = list_process->color_start;
		if (start > list_process->pc)
			vm->mem[((start - 2) % MEM_SIZE)][MEM_DESC] = NULL_COLOR;
		else
		{
			while (start < list_process->pc)
			{
				if (list_process->curent_instruction.id_opr == NULL_COLOR)
				{
					if (vm->mem[((start) % MEM_SIZE)][MEM_DESC] == PT_COLOR)
						vm->mem[((start) % MEM_SIZE)][MEM_DESC] = NULL_COLOR;
					else
						vm->mem[start][MEM_DESC] = PT_COLOR;
				}
				else
				{
					if (vm->mem[((start - 1) % MEM_SIZE)][MEM_DESC] == PT_COLOR)
						vm->mem[((start - 1) % MEM_SIZE)]
						[MEM_DESC] = NULL_COLOR;
					else if (((start - 1) % MEM_SIZE) == -1)
						vm->mem[(MEM_SIZE - 1)][MEM_DESC] = NULL_COLOR;
					vm->mem[start][MEM_DESC] = list_process->id_parent;
				}
				start++;
			}
		}
	}
}

/*
** ************************************************************************* **
**	a testere rigoureusement   a optimiser  enlever le system de is_alive
**	et faire plus tot des free a la palce
**	ft_printf("process id =%d  pc =%d \n",
**	list_process->id_parent , list_process->pc);
** ************************************************************************* **
*/

BOOL	ft_check_survivor(t_process *list_process, t_vm *vm)
{
	int id_process;

	if (!list_process)
		return (F);
	id_process = 0;
	while (list_process)
	{
		if (!list_process->nbr_live)
		{
			ft_rest_color(vm, list_process);
			list_process->a_live = F;
			ft_temporize(15);
			ft_put_mem(vm->mem);
			id_process--;
		}
		else
		{
			list_process->nbr_live = 0;
			id_process++;
		}
		list_process = list_process->next;
	}
	return (T);
	//	id_process a la fin doit etre == a la taill de la list_process
}


/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

int		ft_get_total_live(t_process *list_process)
{
	int total_live;

	total_live = 0;
	while (list_process)
	{
		total_live += list_process->nbr_live;
		list_process = list_process->next;
	}
	return (total_live);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL		execution(t_vm *vm, t_process *process)
{
	BOOL	(*action_instructions[NBR_OP])(t_vm *vm, t_process *process);

	if (process->curent_instruction.id_opr != -1)
	{
		if (process->curent_instruction.id_opr > 0
		&& process->curent_instruction.id_opr <= NBR_OP)
		{
			init_tab_instruction(action_instructions);
			action_instructions[process->curent_instruction.id_opr]
(vm, process);
		}
/*
		else
		{
			kill the process :
			set the process as kiled
		or
			free the process
		}
*/
	}
	(void)vm;
	return (T);
}

static void run_cycle(t_vm *vm, t_process *list_process, t_op *op_tab[NBR_OP])
{
	t_process *pt_list_process;
	BOOL	v = F;

	pt_list_process = list_process;
	while (list_process)
	{
		if (list_process->a_live)
		{
			v= T;
			if (list_process->time_to_exe > 0)
				list_process->time_to_exe--;
			else
			{
				if(list_process->curent_instruction.id_opr != -1) 
					ft_rest_color(vm, list_process);
				execution(vm, list_process);
				ft_bzero((&list_process->curent_instruction),
				sizeof(list_process->curent_instruction));
				ft_get_next_instuction(&list_process->curent_instruction, vm,
					list_process, op_tab);
				list_process->time_to_exe = op_tab[list_process->curent_instruction.id_opr]->cycle;
			}
		}
		list_process = list_process->next;
	}
	if (!v)
	{
		ft_printf("say winer ............!!!!!!!!!!!!!!\n\n");
		exit(0);
	}
	ft_put_mem(vm->mem);
}

void		ft_fight(t_vm *vm, t_process *list_process)
{
	t_op	*op_tab[NBR_OP];
	int 	cycle_to_die;
	int		time_total;
	int 	check;
	int 	time;

	ft_get_op_tab(op_tab);
	check = 1;
	cycle_to_die = CYCLE_TO_DIE;
	time_total = 0;
	while (cycle_to_die > 0)
	{
		time = 0;
		while (time < cycle_to_die)
		{
			if (time_total + time == vm->dump)
				ft_dump(vm);
			run_cycle(vm, list_process, op_tab);
			time++;
		}
		time_total += time;
		if (!ft_check_survivor(list_process, vm))
		{
			ft_printf("put wine ... plus de process vivant\n");
			exit(0);
		}
		if (ft_get_total_live(list_process) >= NBR_LIVE)
			cycle_to_die =- CYCLE_DELTA;
		if (check == MAX_CHECKS)
		{
			cycle_to_die -= CYCLE_DELTA;
			check = 1;
		}
		else
			check++;
	}
	ft_free_optab(op_tab);
}
