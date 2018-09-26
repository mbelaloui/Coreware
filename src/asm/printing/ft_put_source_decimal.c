/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_source_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:01:46 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 17:19:51 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static void	put_decimal_delim(int i, BOOL with)
{
	int del;

	del = (with) ? 5 : 6;
	while (i < del)
	{
		ft_printf("\t    -\t\t |");
		i++;
	}
}

static void	put_decimal_source_bis1(int i, t_inst *data)
{
	unsigned char	*ret;
	t_charlist		*arg;
	int				size;

	arg = data->param;
	while (arg)
	{
		size = data->size[i];
		ret = ft_int_to_byts(data->add[i - 2], size);
		if (size == REG_SIZE)
			ft_printf("\t[{green}%.3d{eoc}]\t |", ret[0]);
		else if (size == IND_SIZE)
			ft_printf("     [{red}%.3d{eoc}] [{red}%.3d{eoc}]\t"
					"    |", ret[0], ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{yellow}%.3d{eoc}][{yellow}%.3d{eoc}]"
					" [{yellow}%.3d{eoc}][{yellow}%.3d{eoc}] |"
					, ret[0], ret[1], ret[2], ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_decimal_delim(i, F);
}

static void	put_decimal_source_bis2(int i, t_inst *data)
{
	unsigned char	*ret;
	t_charlist		*arg;
	int				size;

	arg = data->param;
	while (arg)
	{
		size = data->size[i + 1];
		ret = ft_int_to_byts(data->add[i], size);
		if (size == REG_SIZE)
			ft_printf("\t   [{green}%.3d{eoc}]\t |", ret[0]);
		else if (size == IND_SIZE)
			ft_printf("     [{red}%.3d{eoc}] [{red}%.3d{eoc}]\t"
					" |", ret[0], ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{yellow}%.3d{eoc}][{yellow}%.3d{eoc}]"
					" [{yellow}%.3d{eoc}][{yellow}%.3d{eoc}] |"
					, ret[0], ret[1], ret[2], ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_decimal_delim(i, T);
}

static void	put_data_decimal(t_player *player)
{
	t_instlist	*pt;
	int			i;

	pt = player->src;
	while (pt && !(i = 0))
	{
		if (pt->data->opcode)
		{
			ft_printf("| %.2d\t| ", pt->data->add[i++]);
			if (pt->data->size[DESC] == -1)
			{
				ft_printf("  -    |");
				put_decimal_source_bis1(i + 2, pt->data);
			}
			else
			{
				ft_printf(" %.3d   |", pt->data->add[i++]);
				put_decimal_source_bis2(i, pt->data);
			}
			ft_printf("\n");
		}
		pt = pt->next;
	}
}

void		ft_put_decimal_source(t_player *player)
{
	ft_printf(" _____ \t  ______\t   ____\t\t\t   ____\t\t\t   ____\n");
	ft_printf("\n| code \t|  ocp \t |\t   arg1\t\t |\t   arg2\t\t |\t   targ3"
			"\t |\n");
	ft_printf("  ---- \t   ----\t\t   ----\t     \t\t   ----\t     \t\t"
			"   ----\n");
	put_data_decimal(player);
	ft_printf("  ---- \t   ----\t\t   ----\t     \t\t   ----\t     \t\t"
			"   ----\n");
}
