/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_visu2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:51:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 17:13:24 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void		init_visu(void)
{
	initscr();
	start_color();
	init_color(COLOR_WHITE, 999, 999, 999);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	keypad(stdscr, TRUE);
}

void		visu_pause(t_vm *vm)
{
	int		c;

	mvprintw(65, 226, "	PAUSE");
	while (1)
	{
		c = getch();
		if (c == 32 || c == '=')
			break ;
		if (c == 27)
			esc_visu(vm, 0);
	}
	mvprintw(65, 226, "	     ");
}

static void		itoa_hex(long value, char *str, int *i, char *base_str)
{
	if (value >= EXA)
		itoa_hex(value / EXA, str, i, "0123456789abcdef");
	str[(*i)++] = base_str[value % EXA];
}

void			print_map(t_vm *vm)
{
	char	buf[AREA_MAP];
	int		i;
	int		j;
	int		id;

	i = 0;
	j = 0;
	ft_bzero(buf, MEM_SIZE * 3);
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
		{
			if (!(id < 0 || id > 30))
				wattron(vm->map, COLOR_PAIR(id));
			wprintw(vm->map, "%s", buf);
			ft_bzero(buf, MEM_SIZE * 3);
			j = 0;
		}
	}
	wrefresh(vm->map);
}
