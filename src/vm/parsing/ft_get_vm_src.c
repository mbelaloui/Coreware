/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:25:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/17 15:08:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"
/*
			if(arg_3 == REG_CODE)
			{
				ft_printf("registre ");
				i++;
			}



			else if(arg_3 == DIR_CODE)
			{
				ft_printf("direct ");
				int pas = op_tab[opr]->size_label;
				i+= pas ;
			}

			else if(arg_3 == DIR_CODE)
			{
				ft_printf("direct ");
				i+= 2;
			}

			else if(arg_3 == DIR_CODE)
			{
				ft_printf("direct ");
				i++;
			}



			else if(arg_3 == IND_CODE)
			{
				ft_printf("indirect ");
				i += 2;
			}else
				ft_printf("no arg 1");



			else if(arg_3 == IND_CODE)
			{
				ft_printf("indirect ");
				i+= 2;
			}
			else
				ft_printf("no arg 3");



			else if(arg_3 == IND_CODE)
			{
				ft_printf("indirect ");
				i +=2;//= pas;
			}else
				ft_printf("no arg 2");
			ft_printf("\n");
*/
t_instlist	*ft_get_vm_src(int fd, int size_prog)
{
	unsigned char buf[1];
	char *src;
	int i;

	i = 0;
	src = ft_strnew(size_prog);
	while(i < size_prog)
	{
		if(!read(fd, &buf, 1))
		{
			ft_printf("eoor\n");
			exit(0);
		}
		src[i] = buf[0];
		ft_printf("i =[%xd] = %x\t",i,
				src[i]);
		if(i % 4 == 0)
			ft_printf("\n");
		i++;
	}
	/*
	 *	src = get_vm_src(fd);
	 *		ft_printf("\nsrc {green} ok %S\n<%d>{eoc}\n", src, ft_strlen(src));
	 *		*/
	i = 0;
	ft_printf("\n\n/ ************************** \\ \n\n", src[i]);
	while(i < size_prog)
	{
		ft_printf("%.2x ", (unsigned char)src[i]);
		i++;
		if (i % 8 == 0)
			ft_printf("  ");
		if (i % 16 == 0)
			ft_printf("\n");
	}
	ft_printf("\n\n/ ************************** \\ \n\n", src[i]);
	t_op *op_tab[NBR_OP];
	ft_get_op_tab(op_tab);
	ft_put_size_label(op_tab);
	int opr = 0;
	i = 0;
	while(i < size_prog)
	{
		opr = src[i];
		ft_printf(" i = %d\n", i);
		if (src[i] < 17 && src[i] > 0)// error
			ft_printf("{green} op = %.2x {eoc}", src[i]);
		else
		{
			ft_printf("{red} exit %d   [%d]{eoc}", i, src[i]);

			break;
		}
		ft_printf(" name {%s} nbr param %d "
				, op_tab[opr]->name, op_tab[opr]->nbr_param);
		//opr = src[i];
		i++;
		if (opr == 1 || opr == 12 || opr == 9)
		{
			if (opr == 12 || opr == 9)
				i+= 2;
			else
				i += 4;
		}
		else if(ft_is_need_desc_op( op_tab[opr]->name, op_tab))
		{
			ft_printf(" {yellow}desc{eoc} [%.2x] ",(unsigned char) src[i]);
			ft_printf(" {yellow}desc{eoc} [%.8b] \n",(unsigned char) src[i]);

			unsigned char desc = src[i];
			i++;
			ft_printf(" desc arg  = %.8b \n", (unsigned char)desc);
			//
			////desc = desc >> 2;

			unsigned char arg_3;// = desc & 0x3;
			//desc = desc >> 2;
			arg_3 = desc >> 6;
			ft_printf(" desc arg 1 = %.32b ", (unsigned char)arg_3);
			if(arg_3 == REG_CODE)
			{
				ft_printf("registre ");
				i++;
			}
			else if(arg_3 == DIR_CODE)
			{
				ft_printf("direct ");
				int pas = op_tab[opr]->size_label;
				i+= pas ;
			}else if(arg_3 == IND_CODE)
			{
				ft_printf("indirect ");
				i += 2;
			}else
				ft_printf("no arg 1");

			ft_printf("\n");
			//desc = desc >> 2;
			unsigned char	arg_q = (desc << 2);
			arg_3 = arg_q >> 6;
			ft_printf(" desc arg 2 = %.32b ", (unsigned char)arg_3);
			if(arg_3 == REG_CODE)
			{
				ft_printf("registre ");
				i++;
			}else if(arg_3 == DIR_CODE)
			{
				ft_printf("direct ");
				i++;
			}
			else if(arg_3 == IND_CODE)
			{
				int pas = op_tab[opr]->size_label;
				ft_printf("indirect  pas = %d", pas);
				i +=2;//= pas;
			}else
				ft_printf("no arg 2");
			ft_printf("\n");
			arg_q = (desc << 4);
			arg_3 = arg_q >> 6;
			ft_printf(" desc arg 3 = %.32b ", (unsigned char)arg_3);
			if(arg_3 == REG_CODE)
			{
				ft_printf("registre ");
				i++;
			}
			else if(arg_3 == DIR_CODE)
			{
				ft_printf("direct ");
				i+= 2;
			}else if(arg_3 == IND_CODE)
			{
				ft_printf("indirect ");
				i+= 2;
			}
			else
				ft_printf("no arg 3");
	/*
	 * int arg_1 = DESC_REG & ;
	 * int arg_2 = DESC_DIR & ;
	 * int arg_3 = DESC_IND & ;
	 * */

	// faire des decalage binaire >> 2 et extraire  les deux bit tout a fait a roite puis les
	// comparer avec >REG_CODE/DIR_CODE/IND_CODE< pour conaitre le type des l'args
	// en conaissant le type des args ont peut deduire
	// si le type est bien coherent
	// <si la desc dit qu'il ya un reg et le n			um est superieur a ce qui est reconnu>
	// la taille de representation de chaque arg

	/*
	 * //if (src[i] & T_REG_P1)
	 * ft_printf("1 REG - size = {%d}, [%.8b]\n", op_tab[opr],
	 * T_REG_P1);
	 * if (src[i] & T_R	EG_P2)
	 * ft_printf("2 REG - size = {%d}, [%.8b]\n", op_tab[opr],
	 * T_REG_P2);
	 * //if (src[i] & T_REG_P3)
	 * ft_printf("3 REG - size = {%d}, [	%.8b]\n", op_tab[opr],i
	 * T_REG_P3);
	 * */

		}
		else
			i++;
	//is need OCP <+1> else faire directement les tailles des arguments

	//size parame      ->error
		ft_printf("\n");
	//ft_printf("%.2x ", (unsigned char)src[i		]);
	/*i = i + op_tab[opr]->nbr_param;
	  if (i == j)
	  i = size_pro				g;
	  else
	  j = i;
	  *///if (i % 8 == 0)
	//ft_printf("  ");
	//if							(i % 16 == 0)
	//ft_printf("\n");

	char *l= NULL;
		get_next_line(0, &l);
		ft_strdel(&l);
		//ft_temporize(5);
	}

	ft_printf(" end index		 = %d\n", i);
	//ft_oct_to_instlist(src);
	ft_free_optab(op_tab);
	ft_strdel(&src);
	return (NULL);
}
