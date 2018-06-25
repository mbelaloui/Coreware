#include "../../inc/asm.h"

void    run(char *url_file)
{
	// good format of file
        ft_is_good_format_param(url_file);
	// get info file and check is well formated

	//check options and print datas if mantioned

	// translate file .s to file .cor
}

int	main(int argc, char **argv)
{
	unsigned long op;
	char *param;
	int pt;

	op = 0;
	param = ft_mat_to_str(argv, 1);
	pt = ft_extract_options(param, &op, ft_is_option,ft_set_options );

//	faire attention a l'option {-o + output } si non l'enlever carrement
//	si non mettre un nom par defaut s'il ya pas un nom valide 
//	s\il ya directement une url d'un fichier valide

	if (pt < 0)
		ft_error_param(ERROR_BAD_PARAM, param);
	else if (argc == 1)
		ft_error_param(ERROR_NO_PARAM, param);
	else
		run(param + pt);
	return (0);
}
