#include "../../inc/vm.h"

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
