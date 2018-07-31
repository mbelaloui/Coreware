#include "../../inc/asm.h"

void		ft_error_reading_file(int error)
{
	ft_printf("{red}EROOR {eoc}: ");
	if (ERROR_READING_FILE == error)
		ft_printf("the file doesn't exist\n");
	else if (ERROR_EMPTY_FILE == error)
		ft_printf("the file is empty\n");
	else if (ERROR_BAD_CHAR_FILE == error)
		ft_printf("forbidden char <%c> found in file\n", SEP);
/*	else if (ERROR_ == error)
		ft_printf("{red}wrong param{eoc} : \"%s\""
				" : option not reconized.\n", param);
*/	exit(error);
}
