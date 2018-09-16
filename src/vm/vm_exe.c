#include "../../inc/vm.h"

/*****************************************************************/
		//option
/*****************************************************************/
/*BOOL	is_option_valide(char *param)
{
	if (param)
	{
		if (param[0] == '-' && ft_isalpha(param[1])
			&& (!param[2] || ft_isblank(param[2])))
			return (T);
	}
	return (F);
}
*/
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

// close the file after reading in the asm and the vm

/*****************************************************************/
	//VM
/*****************************************************************/
/*BOOL	ft_check_signature(unsigned char r[4])
{
	unsigned int *ret;
	int i;
	int size;

	size = sizeof(int);
	ret = ft_int_to_byts(COREWAR_EXEC_MAGIC, size);
	i = 0;
	while (i < size)
	{
		if (r[i] != ret[i])
		{
//			ft_printf("ici %d   %d\n", r[i], ret[i]);
			free(ret);
			return (F);
		}
		i++;
	}
	free(ret);
	return (T);	
}
*/
/*****************************************************************/
		//ft_put_oct.c
/*****************************************************************/
/*void	ft_put_oct(unsigned char r[4])
{
	ft_printf("[%c, %c, %c, %c]", r[0], r[1], r[2], r[3]);
	ft_printf("[%.3d, %.3d, %.3d, %.3d]", r[0], r[1], r[2], r[3]);
}
*/
/*****************************************************************/
		//ft_get_next_oct.c
/*****************************************************************/
BOOL	ft_get_next_oct(int fd, unsigned char (*tab)[4])
{
	unsigned char buf[1];
	int i;
	int size;

	i = 0;
	size = sizeof(int);
	while ( i < size)
	{
		if (!read(fd, &buf, 1))
			return (F);
		(*tab)[i] = buf[0];
//		ft_printf("i =[%d] = %d\t",i, buf[0]);
		i++;
	}
//	ft_printf("\n");
	return (T);
}

/*****************************************************************/
		//ft_byts_to_int.c
/*****************************************************************/
int	ft_byts_to_int(unsigned char b[4])
{
	return ((((((b[0] << 8) | b[1]) << 8) | b[2]) << 8) | b[3]);
}


/*****************************************************************/
		//ft_u_str_to_str.c
/*****************************************************************/
char	*ft_u_str_to_str(unsigned char str[4])
{
	char *ret;
	int i;

	i = 0;
	ret = ft_strnew(4);
	while (i < 4)
	{
		ret[i] = str[i];
//		ft_printf("i =[%d] = %d\t",i, ret[i]);
		i++;
	}
//	ft_printf("\n");
	return (ret);
}

/*****************************************************************/
		//ft_get_vm_magic.c
/*****************************************************************/
void	ft_get_vm_magic(int fd)
{
	unsigned char oct[4];

	if (!ft_get_next_oct(fd, &oct))
	{
		ft_printf("{red}Error reading file"
		"<probleme signature> reaching unexpecting eof 1\n{eoc}");
		exit(0);
	}
//	ft_put_oct(oct);
	if (!ft_check_signature(oct)) // detailes option bonus
	{
		ft_printf("{red}signature Ko\n{eoc}");
		exit(0);
	}
	else
		ft_printf("signature {green}ok\n{eoc}");
}

/*****************************************************************/
		//ft_get_vm_name.c
/*****************************************************************/
char	*ft_get_vm_name(int fd)
{
	unsigned char oct[4];
	char *name;
	char *temp;
	int byt;
	
	byt = 0;
	name = NULL;
	while(byt < (PROG_NAME_LENGTH / 4))
	{
		ft_bzero(&oct, sizeof(oct));
		if (!ft_get_next_oct(fd, &oct))
		{
			ft_printf("{red}Error reading file"
			"<name part> reaching unexpecting eof 2\n{eoc}");
			ft_printf("{red}Error while reading name Ko\n{eoc}");
			exit(0);
		}
	//	if (byt % 2)
	//		ft_printf("\n");
	//	ft_put_oct(oct);
		temp = ft_u_str_to_str(oct);
		name = ft_strjoin_clear(&name, &temp, BOTH);
		byt++;
	}
	return (name);
}

/*****************************************************************/
		//ft_get_vm_size.c
/*****************************************************************/
int	ft_get_vm_size(int fd)
{
	unsigned char oct[4];
	int size;
	
	size = 0;
	if (!ft_get_next_oct(fd, &oct))
	{
		ft_printf("{red}Error reading file"
		"<size programme> reaching unexpecting eof 1\n{eoc}");
		exit(0);
	}
//		ft_put_oct(r);
	size = ft_byts_to_int(oct);
	if(size > CHAMP_MAX_SIZE)
	{
		ft_printf("{red}Error size programme"
		"<size programme = %d> can not be superior to 1\n{eoc}",
		size, CHAMP_MAX_SIZE);
		exit(0);
	}
	return (size);
}

/*****************************************************************/
		//ft_is_null.c
/*****************************************************************/
BOOL	ft_is_null(int fd)
{
	unsigned char oct[4];
	int	val;

	if (!ft_get_next_oct(fd, &oct))
	{
		ft_printf("{red}Error reading file"
		"<null format> reaching unexpecting eof 1\n{eoc}");
		exit(0);
	}
//		ft_put_oct(r);
	val = ft_byts_to_int(oct);
	if(val)
	{
		ft_printf("{red}Error fomrat programme"
		"<null programme>\n{eoc}");
		exit(0);

	}
	return (T);
}

/*****************************************************************/
		//ft_get_vm_comment.c
/*****************************************************************/
char	*ft_get_vm_comment(int fd)
{
	unsigned char oct[4];
	char *comment;
	char *temp;
	int byt;
		
	byt = 0;
	comment = NULL;
	while(byt < (PROG_COMMENT_LENGTH / 4))
	{
		ft_bzero(&oct, sizeof(oct));
		if (!ft_get_next_oct(fd, &oct))
		{
			ft_printf("{red}Error reading file"
			"<comment part> reaching unexpecting eof 3\n{eoc}");
			ft_printf("{red}Error while reading name Ko\n{eoc}");
			exit(0);
		}
//		if (t % 2)
//			ft_printf("\n");
//		ft_put_oct(r);
		temp = ft_u_str_to_str(oct);
		comment = ft_strjoin_clear(&comment, &temp, BOTH);
		byt++;
	}
	return (comment);
}

/*****************************************************************/
		//ft_get_vm_src.c
/*****************************************************************/
/*char		*get_vm_src(int fd)
{
	unsigned char oct[4];
	char *src;
	char *temp;
	BOOL rd;

	rd = T;
	src = NULL;
	while(rd)
	{
		ft_bzero(&oct, sizeof(oct));
		if (!ft_get_next_oct(fd, &oct))
			rd = F;
		temp = ft_u_str_to_str(oct);
		src = ft_strjoin_clear(&src, &temp, BOTH);
	}
	return (src);
}
*/

/*****************************************************************/
		//ft_get_type_args_bin.c
/*****************************************************************/
/*int	is_direct(int ocp, int pos)
{
	if (pos == 1)
		return (T_DIR_P1);
	else if (pos == 2)
		return (T_DIR_P2);
	else
		return (T_DIR_P3);
}

int	is_indirect(int ocp, int pos)
{
	if (pos == 1)
		return (T_IND_P1);
	else if (pos == 2)
		return (T_IND_P2);
	else
		return (T_IND_P3);
}

int	is_register(int ocp, int pos)
{
	if (pos == 1)
		return (T_REG_P1);
	else if (pos == 2)
		return (T_REG_P2);
	else
		return (T_REG_P3);
}
*/
/*
	utiliser les printf pour afficher le type des variables 
	dans la vm !!!!
*/
/*
int	ft_get_type_args_bin(int ocp, int nbr_arg)
{
	if (is_direct(ocp, id_arg))//ft_printf("{red} DIRECT {eoc}");
		return (get_id_pos_direct(pos + 1));	
	if (is_indirect(ocp, id_arg))//ft_printf("{yellow} INDIRECT {eoc}");
		return (get_id_pos_indirect(pos + 1));	
	if (is_register(ocp, id_arg))//ft_printf("{BLUE} registre {eoc}");
		return (get_id_pos_register(pos + 1));	
	return (0);
}
i*/


t_instlist	*ft_get_vm_src(int fd, int size_prog)
{
	char *src;
	unsigned char buf[1];
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
	src = get_vm_src(fd);
	ft_printf("\nsrc {green} ok %S\n<%d>{eoc}\n", src, ft_strlen(src));
*/
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

			//desc = desc >> 2;
			
			unsigned char arg_3;// = desc & 0x3;
		//	desc = desc >> 2;
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
		//	desc = desc >> 2;
			unsigned char arg_q = (desc << 2);
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
			int arg_1 = DESC_REG & ;
			int arg_2 = DESC_DIR & ;
			int arg_3 = DESC_IND & ;
*/

// faire des decalage binaire >> 2 et extraire  les deux bit tout a fait a roite puis les 
// comparer avec >REG_CODE/DIR_CODE/IND_CODE< pour conaitre le type des l'args
// en conaissant le type des args ont peut deduire
//	si le type est bien coherent
//		<si la desc dit qu'il ya un reg et le num est superieur a ce qui est reconnu>
//	la taille de representation de chaque arg

/*	

		//	if (src[i] & T_REG_P1)
				ft_printf("1 REG - size = {%d}, [%.8b]\n", op_tab[opr],
				T_REG_P1);
		//	if (src[i] & T_REG_P2)
				ft_printf("2 REG - size = {%d}, [%.8b]\n", op_tab[opr],
				T_REG_P2);
		//	if (src[i] & T_REG_P3)
				ft_printf("3 REG - size = {%d}, [%.8b]\n", op_tab[opr],
				T_REG_P3);
*/
		}
		else
		 i++;
		//is need OCP <+1> else faire directement les tailles des arguments

		//size parame      ->error
		ft_printf("\n");
//		ft_printf("%.2x ", (unsigned char)src[i]);
/*				i = i + op_tab[opr]->nbr_param;
		if (i == j)
			i = size_prog;
		else
			j = i;
*///		if (i % 8 == 0)
//			ft_printf("  ");
//		if (i % 16 == 0)
//			ft_printf("\n");

		char *l= NULL;
		get_next_line(0, &l);
		ft_strdel(&l);
//		ft_temporize(5);
	}

	ft_printf(" end index = %d\n", i);
//	ft_oct_to_instlist(src);
	ft_free_optab(op_tab);
	ft_strdel(&src);
	return (NULL);
}

/*****************************************************************/
		//main_vm.c
/*****************************************************************/
int	main(int argc, char **argv)
{
	int fd;
	
	fd = ft_open_r_file(argv[1]);
	ft_get_vm_magic(fd);
	char *name = ft_get_vm_name(fd);
	ft_printf("\nname {green}ok %s\n{eoc}", name);
	ft_strdel(&name);
	if (ft_is_null(fd))
		ft_printf("{green}ok null{eoc}\n");
	else
	{
		ft_printf("{redko{eoc}\n");
		exit(0);
	}
	int size = 0;
	ft_printf("\nsize {green} %d {eoc}\n", size = ft_get_vm_size(fd));

	char *comment;
	ft_printf("\ncomment {green}ok %s\n{eoc}", comment = ft_get_vm_comment(fd));
	ft_strdel(&comment);
	if (ft_is_null(fd))
		ft_printf("{green}ok null{eoc}\n");
	else
	{
		ft_printf("{red}ko{eoc}\n");
		exit(0);
	}
	ft_get_vm_src(fd, size);

	(void)argc;
	(void)argv;
	return (0);
}
