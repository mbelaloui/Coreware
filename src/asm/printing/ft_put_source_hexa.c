/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_source_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:03:37 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/16 11:19:22 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static void	put_hexa_delim(int i, BOOL with)
{
	int del;

	del = (with) ? 5 : 6;
	while (i < del)
	{
		ft_printf("   \t  -  \t    |");
		i++;
	}
}

static void	put_hexa_source_bis1(int i, t_inst *data)
{
	unsigned int	*ret;
	t_charlist		*arg;
	int				size;

	arg = data->param;
	while (arg)
	{
		size = data->size[i];
		ret = ft_int_to_byts(data->add[i - 2], size);
		if (size == REG_SIZE)
			ft_printf("\t[{green}%.2hx{eoc}]\t    | ", ret[0]);
		else if (size == IND_SIZE)
			ft_printf("     [{red}%.2hx{eoc}] [{red}%.2hx{eoc}]\t"
					"    | ", ret[0], ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{yellow}%.2hx{eoc}][{yellow}%.2hx{eoc}]"
					" [{yellow}%.2hx{eoc}][{yellow}%.2hx{eoc}] | "
					, ret[0], ret[1], ret[2], ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_hexa_delim(i, F);
}

static void	put_hexa_source_bis2(int i, t_inst *data)
{
	unsigned int	*ret;
	t_charlist		*arg;
	int				size;

	arg = data->param;
	while (arg)
	{
		size = data->size[i + 1];
		ret = ft_int_to_byts(data->add[i], size);
		if (size == REG_SIZE)
			ft_printf("\t[{green}%.2hx{eoc}]\t    | \t", ret[0]);
		else if (size == IND_SIZE)
			ft_printf("     [{red}%.2hx{eoc}] [{red}%.2hx{eoc}]\t"
					"    |\t", ret[0], ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{yellow}%.2hx{eoc}][{yellow}%.2hx{eoc}]"
					" [{yellow}%.2hx{eoc}][{yellow}%.2hx{eoc}] |\t"
					, ret[0], ret[1], ret[2], ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_hexa_delim(i, T);
}

static void	put_hexa_data(t_player *player)
{
	t_instlist	*pt;
	int			i;

	pt = player->src;
	while (pt && !(i = 0))
	{
		if (pt->data->opcode)
		{
			ft_printf("| %.2x\t| ", pt->data->add[i++]);
			if (pt->data->size[DESC] == -1)
			{
				ft_printf("  -   |");
				put_hexa_source_bis1(i + 2, pt->data);
			}
			else
			{
				ft_printf(" %x   |", pt->data->add[i++]);
				put_hexa_source_bis2(i, pt->data);
			}
			ft_printf("\n");
		}
		pt = pt->next;
	}
}

void		ft_put_hexa_source(t_player *player)
{
	ft_printf(" _____ \t ______\t \t____\t     \t\t____\t     \t\t____\n");
	ft_printf("\n| code \t|  ocp \t|\targ1\t    |\t\targ2\t    |\t\targ3\t"
			"    |\n");
	ft_printf("  ---- \t   ----\t \t----\t     \t\t----\t     \t\t----\n");
	put_hexa_data(player);
	ft_printf("  ---- \t   ----\t \t----\t     \t\t----\t     \t\t----\n");
}
