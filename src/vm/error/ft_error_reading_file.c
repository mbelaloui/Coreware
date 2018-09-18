
#include "../../../inc/vm.h"

int	ft_error_reading_file(int error)
{
	ft_printf("{red}Error reading file {eoc}");
	if (error == ERROR_FORMAT_HEAD)
		ft_printf("the head file is not well formated\n");
	else if (error == ERROR_READING_FILE)
		ft_printf("<comment part> reaching unexpecting eof\n");
	else if (error == ERROR_MAGIC_NUM)
		ft_printf("the file must be corrupt\n");
	else if (error == ERROR_SIZE_FILE)
	{
		ft_printf("the size of the champions must be less than "
                "	%d\n",CHAMP_MAX_SIZE);
	}

	exit(error);
}
