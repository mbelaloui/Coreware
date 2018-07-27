#include "../../inc/asm.h"

void		ft_error_reading_file(int error)
{
	if (ERROR_READING_FILE == error)
		ft_printf("{red}the file doesn't exist{eoc}\n");
/*	else if (ERROR_ == error)
		ft_printf("{red}wrong param{eoc} : \"%s\""
				" : option not reconized.\n", param);
*/	exit(error);
}
