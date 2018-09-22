/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:25:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/22 18:38:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

// file corrupt s'il la taill de src est plus grande que celle declaree

/*******************************************************************************/
/*******************************************************************************/
int		get_size_param(t_op *op_tab[NBR_OP], int id_opr, unsigned char arg)
{
	if (arg == REG_CODE)
		return (REG_SIZE);
	else if (arg == DIR_CODE)
		return (op_tab[id_opr]->size_label);
	else if (arg == IND_CODE)
		return (IND_SIZE);
	else
		return (0);
}

/*******************************************************************************/
			//ft_manage_param.c
/*******************************************************************************/


int		manage_p3(int desc, int opr,t_op *op_tab[NBR_OP])
{
	unsigned char	param;
	unsigned char	arg_q;
	int				size;

	size = 0;
	arg_q = (desc << 4);
	param = arg_q >> 6;
	ft_printf(" i = %.3d   param = %d ", 3, param);
	ft_printf("{yellow}%d {eoc}\n", size = get_size_param(op_tab, opr,  param));
	return (size);
}

int		manage_p2(int desc, int opr,t_op *op_tab[NBR_OP])
{
	unsigned char	param;
	unsigned char	arg_q;
	int				size;

	size = 0;
	arg_q = (desc << 2);
	param = arg_q >> 6;
	ft_printf(" i = %.3d   param = %d ", 2, param);
	ft_printf("{yellow}%d {eoc}\n", size = get_size_param(op_tab, opr,  param));
	return (size);
}
/*
int	get_type_param(int param, int desc_op)
{
	ft_printf();
}
*/
int		manage_p1(int desc, t_op *op, t_op *op_tab[NBR_OP])
{
	unsigned char	param;
	int				size;

	size = 0;
	param = desc >> 6;
/*
	if (op->param & T_DIR_P1)
		ft_printf("{GREEN}direct{eoc}");
	if (op->param & T_REG_P1)
		ft_printf(" {RED}registre{eoc}");
	if (op->param & T_IND_P1)
		ft_printf(" {YELLOW}indirect{eoc}");
i*/

//	get_type_param(param, ft_get_type_param(op));

	ft_printf(" praram [%.9b]\n", op->param);
	ft_printf(" i = %.3d   param = %d ", 1, param);
	ft_printf("  {yellow}%d {eoc}\n", size = get_size_param(op_tab, op->mnemonique,  param));

	return (size);
}

int	add_to_inst(char *src, t_int_list **inst_src, int size)
{
	int pt;

	pt = 0;

	//fonction byte to int et ajouter le resultat a la list

	while (pt < size)
		ft_add_end_intlist(src[pt++], inst_src);
	return (size);
}
/*
BOOL		is_dex_ok(desc, op, op_tab)
{
	
}
*/
		//voir si la description est bien faite


int		ft_manage_param(char *src, int opr, t_int_list **inst_src_list,
		t_op *op_tab[NBR_OP])
{
	int		nbr_oct;
	int		pt;
	unsigned char desc;

	pt = 0;
	if (!ft_is_need_desc_op(op_tab[opr]->name, op_tab))
	{
		nbr_oct = (opr == 1) ? 4 : 2;
		while (nbr_oct-- > 0)
			ft_add_end_intlist(src[pt++], inst_src_list);
	}
	else
	{
		desc = src[pt++];
		ft_add_end_intlist(desc, inst_src_list);
//		ft_printf("\n");
		int size;
	t_op *op = ft_get_op(op_tab, op_tab[opr]->name);
//		is_dex_ok(desc, op, op_tab);
//		size = manage_p1(desc, opr, op_tab);
add_to_inst(src + pt, inst_src_list, size = manage_p1(desc, op, op_tab));
		pt += size;

//		size = manage_p2(desc, opr, op_tab);
add_to_inst(src + pt, inst_src_list, size = manage_p2(desc, opr, op_tab));
		pt += size;

//		size = manage_p3(desc, opr, op_tab);
add_to_inst(src + pt, inst_src_list, size = manage_p3(desc, opr, op_tab));
		pt += size;
		// en conaissant le type des args ont peut deduire
		// si le type est bien coherent
		// <si la desc dit qu'il ya un reg et le num est superieur a ce qui est reconnu>
		// la taille de representation de chaque arg
	}
	//	else
	//		pt++;
	(void) inst_src_list;
	return (pt);
}

/*******************************************************************************/
			//ft_str_to_list_inst.c
/*******************************************************************************/
t_vm_inst	*ft_str_to_list_inst(char *src, t_champ *champ,
		t_op *op_tab[NBR_OP])
{
	t_int_list	*inst_src_list;
	t_vm_inst	*vm_src;
	int			i;
	int			opr;

	i = 0;
	vm_src = NULL;
	while (i < champ->size)
	{
		inst_src_list = NULL;
		opr = src[i];

		ft_printf(" name {%s} nbr param %d\n" , op_tab[opr]->name,
				op_tab[opr]->nbr_param);

		i += ft_manage_opr(opr, &inst_src_list);
		i += ft_manage_param(src + i, opr, &inst_src_list, op_tab);
		ft_add_vm_instlist(inst_src_list, &vm_src);
		ft_clear_intlist(&inst_src_list);
		ft_printf("\n");
	}
	return (vm_src);
}

/*******************************************************************************/
			//ft_get_vm_src.c
/*******************************************************************************/
t_vm_inst	*ft_get_vm_src(int fd, t_champ *champ, t_op *op_tab[NBR_OP])
{
	char		*src;
	t_vm_inst	*src_list;

	src = ft_read_src(fd, champ->size);

	ft_put_raw_src_champ(src, champ->size);

	/*champ->src = */
	src_list = ft_str_to_list_inst(src, champ, op_tab);

	//ft_put_inst_src_vm(champ->src);

	(void)op_tab;

	ft_strdel(&src);
	
//	ft_dell_cham();

	
	return (src_list);
}
