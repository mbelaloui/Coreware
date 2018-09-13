/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_source_bin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:59:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 14:00:48 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	put_bin_delim(int i, BOOL with)
{
	int del;

	del = (with) ? 5 :	6;

	while (i < del)
	{
		ft_printf("   \t\t\t    -\t\t\t  |");
		i++;
	}
}

void	put_bin_source_bis1(int i, t_inst *data)
{
	int size;
	unsigned int *ret;
	t_charlist *arg;

	arg = data->param;
	while (arg)
	{
		size = data->size[i];
		ret = ft_int_to_byts(data->add[i - 2], size);
		if (size == REG_SIZE)
			ft_printf("\t[{green}%8.8b{eoc}]\t    |", ret[0]);
		else if (size == IND_SIZE)
			ft_printf("     [{red}%8.8b{eoc}] [{red}%8.8b{eoc}]\t"
					"    |", ret[0], ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{blue}%8.8b{eoc}][{blue}%8.8b{eoc}]"
					" [{blue}%8.8b{eoc}][{blue}%8.8b{eoc}] |"
					,ret[0],ret[1],ret[2],ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_bin_delim(i, F);
}

void	put_bin_source_bis2(int i, t_inst *data)
{
	t_charlist *arg;
	int size;
	unsigned int *ret;

	arg = data->param;
	while (arg)
	{
		size = data->size[i + 1];
		ret = ft_int_to_byts(data->add[i], size);
		if (size == REG_SIZE)
			ft_printf("\t\t\t[{green}%8.8b{eoc}]\t\t  |",ret[0]);
		else if (size == IND_SIZE)
			ft_printf("\t\t  [{red}%8.8b{eoc}] [{red}%8.8b{eoc}]\t"
					"\t  |",ret[0],ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{blue}%8.8b{eoc}][{blue}%8.8b{eoc}]"
					" [{blue}%8.8b{eoc}][{blue}%8.8b{eoc}] |"
					,ret[0],ret[1],ret[2],ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_bin_delim(i, T);
}

void	put_bin_data(t_player *player)
{
	t_instlist *pt;
	int i;

	pt = player->src;
	while (pt && !(i = 0))
	{
		if (pt->data->opcode)
		{
			ft_printf("| %8.8b |", pt->data->add[i++]);
			if (pt->data->size[DESC] == -1)
			{
				ft_printf("\t -    |");
				put_bin_source_bis1(i + 2, pt->data);
			}
			else
			{
				ft_printf(" %8.8b |", pt->data->add[i++]);
				put_bin_source_bis2(i, pt->data);
			}
			ft_printf("\n");
		}
		pt = pt->next;
	}
}

void	ft_put_bin_source(t_player *player)
{
	ft_printf("    _____\t___\t	\t\t  ____\t\t\t\t\t\t   ____ \t\t\t\t\t"
			"   ____\n");
	ft_printf("\n|   code   |    ocp   |\t\t\t  arg1\t\t\t  |\t\t\t   arg2"
			"\t\t\t  |\t\t\t   arg3\t\t\t  |\n");
	ft_printf("    ---- \t---\t \t\t  ----\t     \t\t\t\t\t   ---- \t\t\t"
			"\t\t   ----\n");
	put_bin_data(player);
	ft_printf("    ---- \t---\t \t\t  ----\t     \t\t\t\t\t   ---- \t\t\t"
			"\t\t   ----\n");
}
