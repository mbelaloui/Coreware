#include "../../inc/asm.h"

#define MASK_OP_A	0x1
#define MASK_OP_B	0x2
#define MASK_OP_C	0x4
#define MASK_OP_D	0x8
#define MASK_OP_E	0x10
#define MASK_OP_F	0x20
#define MASK_OP_G	0x40
#define MASK_OP_H	0x80
#define MASK_OP_I	0x100
#define MASK_OP_J	0x200
#define MASK_OP_K	0x400
#define MASK_OP_L	0x800
#define MASK_OP_M	0x1000
#define MASK_OP_N	0x2000
#define MASK_OP_O	0x4000
#define MASK_OP_P	0x8000
#define MASK_OP_Q	0x10000
#define MASK_OP_R	0x20000
#define MASK_OP_S	0x40000
#define MASK_OP_T	0x80000
#define MASK_OP_U	0x100000
#define MASK_OP_V	0x200000
#define MASK_OP_W	0x400000
#define MASK_OP_X	0x800000
#define MASK_OP_Y	0x1000000
#define MASK_OP_Z	0x2000000
/**************************************************************/
// deux fonctions q redefinir a chaque fois pour chaque projet
// puis les passer en paramettres sur fonction pour la fonction extract options

static BOOL	ft_is_option(const char option)
{
	if (option == 'o' || option == 'a')// || option == 'l' || option == 'm'
		return (T);
	return (F);
}

static void	ft_set_options(char c, unsigned long *op)
{
	if (c == 'o')
		(*op) = (*op) | MASK_OP_O;
	else if (c == 'a')
		(*op) = (*op) | MASK_OP_A;
/*	else if (c == '')
*/}
/************************************************************************/

/************************************************************************/
//extract option la mettrea dans la lib pour l'utiliser dans tou tles prochain projets 
// ajouter un efonction pour affihcer en binaire les options
// une autre plus claire pour voir les option qui sont activer
// ajouter un commentaire pour les entrees et les sorties de cette fonction

// pour push swap ajouter le teste des nbr < 0 dans le projet
 
int	ft_extract_options(char *param,unsigned long *op)
{
	int index;

	index = 0;
	while (param[index])
	{
		if (param[index] == '-')
		{
			index++;
			if (ft_is_option(param[index]) && param[index + 1] == ' ')
				ft_set_options(param[index], op);
			else
				return (index); // puis tester si valde ou pas la ont recupr just les options 
			
			//(faire le test pour le parammettre de -o out_put.cor ici si jamais je laisse cette option)
			index++;
		}
		else
			return (index);	
		index++;
	}
	return (index);
}
/************************************************************************/

void		ft_put_error(int error)
{
	if (ERROR_NO_PARAM == error)
		ft_printf("wrong nbr of param\n");

	exit(error);		
}

BOOL		is_good_format(char *url_file)
{
	char **temp;
	temp = ft_strsplit(url_file, '.');

	if (ft_matlen(temp) != 2)
	{
		ft_printf("wrong format of file %s\n", url_file);
		exit(2);
	}


ft_printf("nbr of partis %s\n", temp[1]);
	if ( temp[1][0] != 's')
	{
		ft_printf("wrong extention file has to be file.s  not tacke just extention  %s\n", url_file);
		exit(1);
	}	
	
	return (T);	
}

void		run_pass_one(char *url_file)
{

	if (ft_isempty(url_file))
	{
		ft_printf("erreur no url file\n");
	}
	if (ft_comptword(url_file, ' ') != 1)
	{
		ft_printf("Error wrong format of url file\n");
		exit(1);
	}
	else if (is_good_format(url_file))
			ft_printf("ouvrire le fichier est commancer a exraire les infos\n", url_file);

}

int		main(int argc, char **argv)
{
	unsigned long op;
	char *param;
	int pt;

	op = 0;
	param = ft_mat_to_str(argv, 1);
	pt = ft_extract_options(param, &op);
	if (pt < 0)
		ft_printf("error bas options\n",op, pt);
	else if (argc == 1)
		ft_put_error(ERROR_NO_PARAM);
	else
	{
//		ft_printf("options <%.32b>... : \nret pt = %d\n",op, pt);
		run_pass_one(param + pt);
	}
	return (0);
}
