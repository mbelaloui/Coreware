/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:25:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 18:53:26 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

// file corrupt s'il la taill de src est plus grande que celle declaree

/*******************************************************************************/
		//ft_put_inst_src_vm.c
/*******************************************************************************/
void	ft_put_inst_src_vm(t_vm_inst *vm_src)
{
	int		num;

	num = 0;
	ft_printf("\n\nPrinting src\n");
	ft_printf("--------------------------------\n");
	while (vm_src)
	{
		ft_printf("[%.3d]\t : \t", num++);
		ft_put_hex_intlist(vm_src->src);
		ft_printf("---------------------------------------\n");
		vm_src = vm_src->next;
	}
}
/*******************************************************************************/
			//ft_read_src.c
/*******************************************************************************/

/*
** faire une fonction pour lie un oct en plus 
** si le eof n'est pas atteint alors error file corrupt
** si eof ok le file contien bien ce qu'il dis qu'il contien  XD
*/

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
	if (read(fd, &buf, 1))
		ft_error_reading_file(ERROR_MAGIC_NUM);
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
			//ft_manage_opr.c
/*******************************************************************************/
int		ft_manage_opr(int opr, t_int_list **inst_src_list,
t_op	*op_tab[NBR_OP])
{
	if (opr < 17 && opr > 0)
	{
		ft_printf(" name {%s} nbr param %d\n" , op_tab[opr]->name,
				op_tab[opr]->nbr_param);
		ft_add_end_intlist( opr, inst_src_list);
	}
	else
	{
		ft_printf("{blue} ici 1{eoc}\n");
		ft_error_reading_file(ERROR_FORMAT_FILE);
	}
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

	ft_printf(" praram [%.9b]\n", ft_get_type_param(op));
	ft_printf(" i = %.3d   param = %d ", 1, param);
	ft_printf("  {blue}%d {eoc}\n", size = get_size_param(op_tab, op->mnemonique,  param));

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

BOOL		is_dex_ok(desc, op, op_tab)
{
	
}

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
		//voir si la description est bien faite
		desc = src[pt];
		ft_add_end_intlist(desc, inst_src_list);
		pt++;
//		ft_printf("\n");
		int size;
		
	t_op *op = ft_get_op(op_tab, op_tab[opr]->name);
		is_dex_ok(desc, op, op_tab);
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
			//ft_new_vm_inst.c
/*******************************************************************************/
t_vm_inst	*ft_new_vm_inst(t_int_list *src)
{
	t_vm_inst	*ret;

	if (!(ret = malloc(sizeof(*ret))))
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
/*
	ft_printf("****************\n");
		ft_put_hex_intlist(temp_node->src);
	ft_printf("****************\n");
*/	

/*******************************************************************************/
		//champ.c
/*******************************************************************************/

BOOL    ft_dell_inst_sr(t_vm_inst **to_free)
{
	t_vm_inst *pt;
	t_int_list	*temp;

	if (!to_free || !(*to_free))
		return (F);
	pt = *to_free;
	while (*to_free)
	{
		pt = *to_free;
		temp = pt->src;
		ft_clear_intlist(&temp);

/*		
		ft_printf("----------------\n");
		ft_put_hex_intlist(temp);
		ft_printf("----------------\n");
*/

		*to_free = (*to_free)->next;
		free(pt);
	}
	*to_free = NULL;
	return (T);
}
/*
void    ft_dell_cham(t_champ **champ)
{
       ft_strdel(&(*champ)->name);
       ft_strdel(&(*champ)->comment);
	//      ft_dell_inst_src(&(*champ)->src);
        free(*champ);
}*/
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

//ft_printf("\n");
	i = 0;
	vm_src = NULL;
	while (i < champ->size)
	{
		inst_src_list = NULL;
		opr = src[i];
		i += ft_manage_opr(opr, &inst_src_list, op_tab);
		ft_printf("----------------\n");
		ft_put_hex_intlist(inst_src_list);
		ft_printf("----------------\n");
		ft_printf(" i = %d\n", i);
		i += ft_manage_param(src + i, opr, &inst_src_list, op_tab);
	
		ft_add_vm_instlist(inst_src_list, &vm_src);
		ft_clear_intlist(&inst_src_list);
		ft_printf("\n");
	}

	ft_put_inst_src_vm(vm_src);
	ft_dell_inst_sr(&vm_src);

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

	/*champ->src = */ft_str_to_list_inst(src, champ, op_tab);

	//ft_put_inst_src_vm(champ->src);

	(void)op_tab;

	ft_strdel(&src);
	
//	ft_dell_cham();

	
	return (NULL);
}
