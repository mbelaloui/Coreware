/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:25:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 13:27:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

// file corrupt s'il la taill de src est plus grande que celle declaree

/*******************************************************************************/
			//ft_read_src.c
/*******************************************************************************/
char		*ft_read_src(int fd, t_champ *champ)
{
	unsigned char buf[1];
	char *src;
	int i;

	i = 0;
	src = ft_strnew(champ->size);
	while (i < champ->size)
	{
		if (!read(fd, &buf, 1))
			ft_error_reading_file(ERROR_READING_FILE);
		src[i] = buf[0];
		i++;
	}
	return (src);
}


/*******************************************************************************/
			//ft_put_raw_src.c
/*******************************************************************************/
void	ft_put_raw_src(char *src, t_champ *champ)
{
	int i;

	i = 0;
	ft_printf("\n\t\t printing raw src", src[i]);
	ft_printf("\n\t/ ***************************** \\ \n\n", src[i]);
	while(i < champ->size)
	{
		ft_printf("%.2x ", (unsigned char)src[i]);
		i++;
		if (i % 8 == 0)
			ft_printf("  ");
		if (i % 16 == 0)
			ft_printf("\n");
	}
	ft_printf("\n\n\t/ ***************************** \\ \n\n", src[i]);

}


/*******************************************************************************/
/*******************************************************************************/
int		voila(t_op *op_tab[NBR_OP], int id_opr, unsigned char arg)
{
	//	int i;
	//unsigned char arg;// = desc & 0x3;
	//desc = desc >> 2;
	//arg = desc;
	//	ft_printf(" desc arg 1 = %.32b ", (unsigned char)arg_3);
	//	i = 0;
	if (arg == REG_CODE)
	{
		ft_printf("{red}registre{eoc} ");
		return (REG_SIZE);
	}
	else if (arg == DIR_CODE)
	{
		ft_printf("{red}direct{eoc} ");
		return (op_tab[id_opr]->size_label);
	}
	else if (arg == IND_CODE)
	{
		ft_printf("{red}indirect{eoc} ");
		return (IND_SIZE);
	}
	else
		ft_printf("{green}no arg{eoc} ");
	return (0);
}

/*******************************************************************************/
			//ft_manage_opr.c
/*******************************************************************************/
int		ft_manage_opr(int opr, t_int_list **inst_src_list)
{
	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	if (opr < 17 && opr > 0)
	{
		ft_printf(" name {%s} nbr param %d " , op_tab[opr]->name,
				op_tab[opr]->nbr_param);
		ft_add_end_intlist( opr, inst_src_list);
	}
	else
		ft_error_reading_file(ERROR_FORMAT_FILE);
	return (1);
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
	ft_printf(" i = %.3d ", 3);
	ft_printf("{yellow}%d {eoc}\n", size = voila(op_tab, opr,  param));
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
	ft_printf(" i = %.3d ", 2);
	ft_printf("{yellow}%d {eoc}\n", size = voila(op_tab, opr,  param));
	return (size);
}

int		manage_p1(int desc, int opr,t_op *op_tab[NBR_OP])
{
	unsigned char	param;
	int				size;

	size = 0;
	param = desc >> 6;
	ft_printf(" i = %.3d ", 1);
	ft_printf("{yellow}%d {eoc}\n", size = voila(op_tab, opr,  param));
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

int		ft_manage_param(char *src, int opr, t_int_list **inst_src_list,
		t_op *op_tab[NBR_OP])
{
	int		nbr_oct;
	int		pt;
	unsigned char desc;

	pt = 0;
	if (!ft_is_need_desc_op(op_tab[opr]->name, op_tab))//	if (opr == 1 || opr == 9 || opr == 12 || opr == 15)
	{
		nbr_oct = (opr == 1) ? 4 : 2;
		while (nbr_oct > 0)
		{
			ft_add_end_intlist(src[pt++], inst_src_list);
			nbr_oct--;
		}
	}
	else// if (ft_is_need_desc_op(op_tab[opr]->name, op_tab))
	{
		//voir si la description est bien faite
		desc = src[pt];
		ft_add_end_intlist(desc, inst_src_list);
		pt++;
//		ft_printf("\n");
		int size;
		
		size = manage_p1(desc,opr, op_tab);
		add_to_inst(src + pt , inst_src_list, size);
		pt += size;

		size = manage_p2(desc,opr, op_tab);
		add_to_inst(src + pt , inst_src_list, size);
		pt += size;

		size = manage_p3(desc,opr, op_tab);
		add_to_inst(src+pt , inst_src_list, size);
		pt += size;
		// en conaissant le type des args ont peut deduire
		// si le type est bien coherent
		// <si la desc dit qu'il ya un reg et le num est superieur a ce qui est reconnu>
		// la taille de representation de chaque arg
	}
	//	else
	//		pt++;

	return (pt);
}

/*******************************************************************************/
			//ft_new_vm_inst.c
/*******************************************************************************/
t_vm_inst	*ft_new_vm_inst(t_int_list *src)
{
	t_vm_inst	*ret;

	if (!(ret = malloc(sizeof(ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->src = NULL;
	ft_cp_list_intlist(src, &(ret->src));
	ret->size = ft_size_intlist(src);
	ret->next = NULL;
	return (ret);
}

/*******************************************************************************/
			//ft_add_vm_instlist.c
/*******************************************************************************/
BOOL	ft_add_vm_instlist(t_int_list *src, t_vm_inst **list)
{
	t_vm_inst		*temp_node;
	t_vm_inst		*pt_list;

	if (!(temp_node = ft_new_vm_inst(src)))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	if (!(*list))
		*list = temp_node;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = temp_node;
	}
	return (T);
}

void	ft_put_inst(t_vm_inst *vm_src)
{
	while (vm_src)
	{
		ft_put_hex_intlist(vm_src->src);
		ft_printf("\n--------------------------\n");
		vm_src = vm_src->next;
	}
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
		i += ft_manage_opr(opr, &inst_src_list);
		i += ft_manage_param(src + i, opr, &inst_src_list, op_tab);
		ft_add_vm_instlist(inst_src_list, &vm_src);
		ft_clear_intlist(&inst_src_list);
	}
// faire une fonction pour lie un oct en plus 
	// si le eof n'est pas atteint alors error file corrupt
	// si eof ok le file contien bien ce qu'il dis qu'il contien  XD
	return (vm_src);
}

/*******************************************************************************/
			//ft_get_vm_src.c
/*******************************************************************************/
t_instlist	*ft_get_vm_src(int fd, t_champ *champ, t_op *op_tab[NBR_OP])
{
	char		*src;

	src = ft_read_src(fd, champ);

	ft_put_raw_src(src, champ);

	champ->src = ft_str_to_list_inst(src, champ, op_tab);

	ft_strdel(&src);
	return (NULL);
}
