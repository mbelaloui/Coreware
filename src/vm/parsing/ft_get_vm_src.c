/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:25:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/24 15:31:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

// file corrupt s'il la taill de src est plus grande que celle declaree

//	utiliser cette fonction pour afficher les params dans le tqb de l'asm
/*******************************************************************************/
			//ft_manage_p3.c
/*******************************************************************************/
BOOL	is_good_arg3_type(int arg, int desc)
{
	if (arg == REG_CODE)
		if (desc & T_REG_P1)
			return (T);
	if (arg == DIR_CODE)
		if (desc & T_DIR_P1)
			return (T);
	if (arg == IND_CODE)
		if (desc & T_IND_P1)
			return (T);
	return (F);
}

int		ft_manage_p3(int desc, t_op *op,t_op *op_tab[NBR_OP])
{
	unsigned char	arg;
	unsigned char	arg_temp;
	int				size;

	size = 0;
	arg_temp = (desc << 4);
	arg = arg_temp >> 6;
	if (is_good_arg3_type(arg, op->param))
		size = ft_get_size_param(op_tab, op->mnemonique,  arg);
	else
	{
		ft_printf("33333 voila error bad decription param in argument\n");
		exit(-555555555);
	}
	return (size);
}


/*******************************************************************************/
			//ft_manage_p2.c
/*******************************************************************************/
BOOL	is_good_arg2_type(int arg, int desc)
{
	if (arg == REG_CODE)
		if (desc & T_REG_P2)
			return (T);
	if (arg == DIR_CODE)
		if (desc & T_DIR_P2)
			return (T);
	if (arg == IND_CODE)
		if (desc & T_IND_P2)
			return (T);
	return (F);
}

int		ft_manage_p2(int desc, t_op *op, t_op *op_tab[NBR_OP])
{
	unsigned char	arg;
	unsigned char	arg_temp;
	int				size;

	size = 0;
	arg_temp = (desc << 2);
	arg = arg_temp >> 6;
	if (is_good_arg2_type(arg, op->param))
		size = ft_get_size_param(op_tab, op->mnemonique,  arg);
	else
	{
		ft_printf("22222222 :wvoila error bad decription param in argument\n");
		exit(-555555555);
	}
	return (size);
}

/*******************************************************************************/
			//ft_manage_p1.c
/*******************************************************************************/
BOOL	is_good_arg1_type(int arg, int desc)
{
	if (arg == REG_CODE)
		if (desc & T_REG_P1)
			return (T);
	if (arg == DIR_CODE)
		if (desc & T_DIR_P1)
			return (T);
	if (arg == IND_CODE)
		if (desc & T_IND_P1)
			return (T);
	return (F);
}

int		ft_manage_p1(int desc, t_op *op, t_op *op_tab[NBR_OP])
{
	unsigned char	arg;
	int				size;

	size = 0;
	arg = desc >> 6;

	if (is_good_arg1_type(arg, op->param))
		size = ft_get_size_param(op_tab, op->mnemonique,  arg);
	else
	{
		ft_printf("voila error bad decription param in argument\n");
		exit(-555555555);
	}	
	return (size);
}
/*******************************************************************************/
			//ft_manage_param.c
/*******************************************************************************/
int	add_to_inst(char *src, t_int_list **inst_src, int size)
{
//	unsigned char tab[4];
	int pt;

	pt = 0;
/*	int p = 3;
	while (pt < 4)
		tab[pt++]=0;
	pt = 0;
	ft_printf(" \n");
	while (pt < size)
	{
		ft_printf(" src{%d} = %x  ",pt, src[pt]);
		tab[p] = src[pt];
		pt++;
		p--;
	}
	//fonction byte to int et ajouter le resultat a la list
	
	int q = ft_byts_to_int(tab);
	ft_printf("{%d} [%d] [%d] [%d] [%d]\n",q, tab[0] ,tab[1] ,tab[2], tab[3] );
	ft_printf("size {%d}  ",size);

	ft_add_end_intlist(q, inst_src);*/

	while (pt < size)
		ft_add_end_intlist(src[pt++], inst_src);
	return (size);
}

int		ft_manage_param(char *src, t_op *op, t_int_list **inst_src_list,
		t_op *op_tab[NBR_OP])
{
	int		nbr_oct;
	int		pt;
	unsigned char desc;

	pt = 0;
	if (!ft_is_need_desc_op(op->name, op_tab))
	{
		nbr_oct = (op->mnemonique == 1) ? 4 : 2;
		add_to_inst(src + pt, inst_src_list, nbr_oct);
		pt += nbr_oct;
	}
	else
	{
		int size;
		//  dans une sous fonction
		desc = src[pt++];
		ft_add_end_intlist(desc, inst_src_list);
		add_to_inst(src + pt, inst_src_list, size = ft_manage_p1(desc, op, op_tab));
		pt += size;
		if (op->nbr_param > 1)
		{
			add_to_inst(src + pt, inst_src_list, size = ft_manage_p2(desc, op, op_tab));
			pt += size;
			if (op->nbr_param >2)
			{
				add_to_inst(src + pt, inst_src_list, size = ft_manage_p3(desc, op, op_tab));
				pt += size;
			}
		}
	}
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
	t_op 			*op;

	i = 0;
	vm_src = NULL;
	while (i < champ->size)
	{
		inst_src_list = NULL;
		opr = src[i];
		i += ft_manage_opr(opr, &inst_src_list);
		op = ft_get_op(op_tab, op_tab[opr]->name);
		i += ft_manage_param(src + i, op, &inst_src_list, op_tab);
		ft_add_vm_instlist(inst_src_list, &vm_src);
		ft_clear_intlist(&inst_src_list);
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

	src_list = ft_str_to_list_inst(src, champ, op_tab);

	ft_strdel(&src);
	
	return (src_list);
}
