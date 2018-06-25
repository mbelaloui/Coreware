#include "../../inc/asm.h"

void            ft_error_param(int error, char *param)
{
	//extraire les info utils de param

	if (ERROR_NO_PARAM == error) // ici enlever les option et laisser le reste
		ft_printf("{red}wrong nbr of params{eoc} %s\n");
        else if (ERROR_BAD_PARAM == error) // garder les options et enlever le rest
		ft_printf("{red}wrong param{eoc} : %s : option not reconized.\n", param);
	else if (ERROR_NO_URL_FILE == error)
		ft_printf("{red}wrong format param{eoc} : no url file found.\n");
	else if (ERROR_MULTIPUL_PARAM == error)
		ft_printf("{red}wrong format param{eoc} : %s : multipul sources file found.\n", param);
		else if (ERROR_WRONG_FORMAT_FILE == error)
		ft_printf("{red}wrong format file{eoc} : %s : the src file hase to be <*.s>.\n", param);
	// print usage 
	exit(error);
}
