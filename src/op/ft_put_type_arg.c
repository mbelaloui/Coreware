#include "../inc/op.h"

void            ft_put_type_arg(int param)
{
	int i;
	int m;

	i = 1;
	m = 512;
	while (i < 10)
	{
		m = m / 2;
		if (param & m)
			ft_printf("1");
		else
			ft_printf("0");
		if (i % 3 == 0 && i != 9)
			ft_printf(" ");
		i++;
	}
}
