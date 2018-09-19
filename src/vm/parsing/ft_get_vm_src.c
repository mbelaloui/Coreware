/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:25:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/19 16:22:23 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

			/*if(arg_3 == REG_CODE)*/
			/*{*/
				/*ft_printf("registre ");*/
				/*i++;*/
			/*}*/



			/*else if(arg_3 == DIR_CODE)*/
			/*{*/
				/*ft_printf("direct ");*/
				/*int pas = op_tab[opr]->size_label;*/
				/*i+= pas ;*/
			/*}*/

			/*else if(arg_3 == DIR_CODE)*/
			/*{*/
				/*ft_printf("direct ");*/
				/*i+= 2;*/
			/*}*/

			/*else if(arg_3 == DIR_CODE)*/
			/*{*/
				/*ft_printf("direct ");*/
				/*i++;*/
			/*}*/



			/*else if(arg_3 == IND_CODE)*/
			/*{*/
				/*ft_printf("indirect ");*/
				/*i += 2;*/
			/*}else*/
				/*ft_printf("no arg 1");*/



			/*else if(arg_3 == IND_CODE)*/
			/*{*/
				/*ft_printf("indirect ");*/
				/*i+= 2;*/
			/*}*/
			/*else*/
				/*ft_printf("no arg 3");*/



			/*else if(arg_3 == IND_CODE)*/
			/*{*/
				/*ft_printf("indirect ");*/
				/*i +=2;//= pas;*/
			/*}else*/
				/*ft_printf("no arg 2");*/
			/*ft_printf("\n");*/


// file corrupt s'il la taill de src est plus grande que celle declaree

static char		*read_src(int fd, t_champ *champ)
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
//		ft_printf("i =[%xd] = %x\t",i,src[i]);
//		if(i % 4 == 0)
//			ft_printf("\n");
		i++;
	}
	return (src);
}


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


int		manage_opr(int opr, t_int_list **inst_src_list)
{
	t_op	*op_tab[NBR_OP];
	int		i;

	i = 0;
	ft_get_op_tab(op_tab);
	if (opr < 17 && opr > 0)
	{
		ft_printf(" name {%s} nbr param %d " , op_tab[opr]->name, op_tab[opr]->nbr_param);
		ft_add_end_intlist( opr, inst_src_list);
		i++;
	}
	else
		ft_error_reading_file(ERROR_FORMAT_FILE);


	return (i);
}



t_instlist	*ft_get_vm_src(int fd, t_champ *champ)
{
	t_op *op_tab[NBR_OP];
	t_int_list	*inst_src_list;
	char *src;
	int i;
	int opr;

	src = read_src(fd, champ);
	ft_get_op_tab(op_tab);
	inst_src_list = NULL;
	opr = 0;
	i = 0;

	//ft_put_raw_src(src, champ);
	while (i < champ->size)
	{
		opr = src[i];
//		ft_printf(" i = %d\n", i);
	/******************************************** */
			// recuperation de l'opr
	/******************************************** */
		manage_opr(opr, &inst_src_list);
	/******************************************** */
			//gestion de l'ocp
	/******************************************** */

		//opr = src[i];
		int nbr_oct = 0;
		i++;
		if (opr == 1 || opr == 12 || opr == 9 || opr == 15)
		{
			if (opr == 12 || opr == 9 || opr == 15)
				nbr_oct = 2;
			else
				nbr_oct = 4;
			while (nbr_oct > 0)
			{
				ft_add_end_intlist(src[i], &inst_src_list);
				i++;
				nbr_oct--;
			}
		}
		else if(ft_is_need_desc_op( op_tab[opr]->name, op_tab))
		{
			//voir si la description est bien faite
			unsigned char desc = src[i];
			ft_add_end_intlist(src[i], &inst_src_list);
			i++;
			ft_printf("\n");

			unsigned char arg_3;// = desc & 0x3;
			//desc = desc >> 2;
			arg_3 = desc >> 6;
			ft_printf(" i = %.3d ", i);
			ft_printf("{yellow}%d {eoc}\n", i += voila(op_tab, opr,  arg_3));

//			ft_printf("\n");
			//desc = desc >> 2;
			unsigned char	arg_q = (desc << 2);
			arg_3 = arg_q >> 6;
			ft_printf(" i = %.3d ", i);
			ft_printf("{yellow}%d {eoc}\n", i += voila(op_tab, opr,  arg_3));

			
			arg_q = (desc << 4);
			arg_3 = arg_q >> 6;
			ft_printf(" i = %.3d ", i);
			ft_printf("{yellow}%d {eoc}\n", i += voila(op_tab, opr,  arg_3));

	// en conaissant le type des args ont peut deduire
	// si le type est bien coherent
	// <si la desc dit qu'il ya un reg et le num est superieur a ce qui est reconnu>
	// la taille de representation de chaque arg
		}
		else
			i++;
	//is need OCP <+1> else faire directement les tailles des arguments

	//size parame      ->error
		ft_printf("\n");

	char *l= NULL;
		get_next_line(0, &l);
		ft_strdel(&l);
	}

	ft_printf(" end index		 = %d\n", i);
	//ft_oct_to_instlist(src);
	ft_free_optab(op_tab);
	ft_strdel(&src);
	return (NULL);
}
