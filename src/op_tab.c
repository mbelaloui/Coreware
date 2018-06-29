#include "../inc/op.h"

t_op	*ft_new_op_code(char *name, int nbr_param, int mnemonique, int time_exe)
{
	t_op *ret;

	ret = malloc(sizeof(*ret));
	ft_bzero(ret, sizeof(*ret));
	ret->name = ft_strdup(name);
	ret->nbr_param = nbr_param;
	ret->mnemonique = mnemonique;
	ret->cycle = time_exe;
	return (ret);
}

void	ft_put_opt_code(t_op *op_code)
{
	ft_printf("operation   : %s\t|\t", op_code->name);
	ft_printf("nbr param   : %d\n", op_code->nbr_param);
	ft_printf("mnemonique  : %#.2x\t|\t", op_code->mnemonique);
	ft_printf("time exe {cycle}    : %d\n", op_code->cycle);
	ft_printf("description : %s", op_code->description);
}

int		main()
{
	t_op *new = ft_new_op_code("live", 1, 1, 10);


	ft_put_opt_code(new);
	ft_printf("\n\n T_DIR %b\t|\t", T_DIR);
	ft_printf("T_IND %b\t|\t", T_IND);
	ft_printf("T_DIR %b", T_REG);
	return (0);
}
