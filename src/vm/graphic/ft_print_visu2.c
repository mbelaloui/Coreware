/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_visu2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:51:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 19:19:10 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void		itoa_hex(long value, char *str, int *i, char *base_str)
{
	if (value >= EXA)
		itoa_hex(value / EXA, str, i, "0123456789abcdef");
	str[(*i)++] = base_str[value % EXA];
}

static int		continuee(t_vm *vm, int id, char *buf)
{
	if (!(id < 0 || id > 30))
		wattron(vm->map, COLOR_PAIR(id));
	wprintw(vm->map, "%s", buf);
	ft_bzero(buf, AREA_MAP);
	return (0);
}

void			print_map(t_vm *vm)
{
	char	buf[AREA_MAP];
	int		i;
	int		j;
	int		id;

	i = 0;
	j = 0;
	ft_bzero(buf, AREA_MAP);
	wmove(vm->map, 0, 0);
	while (i < MEM_SIZE)
	{
		id = vm->mem[i][MEM_DESC];
		if (vm->mem[i][MEM_SRC] < EXA)
			buf[j++] = '0';
		itoa_hex(vm->mem[i][MEM_SRC], buf, &j, "0123456789abcdef");
		if (i != 63 && ((i + 1) % 64 != 0 || i == 0))
			buf[j++] = ' ';
		i++;
		if (id != vm->mem[i][MEM_DESC] || i == MEM_SIZE)
			j = continuee(vm, id, buf);
	}
	wrefresh(vm->map);
}
