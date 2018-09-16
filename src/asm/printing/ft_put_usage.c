/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:34:56 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/16 11:19:29 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	ft_put_usage(char *name, t_option *op)
{
	ft_printf("Usage :%s [-BdDehHmopsStu] <source-file.s>.\n", name);
	if (!op->h)
		ft_printf("NB : for more informations "
				"please use <%s -h>.\n", name);
	exit(0);
}
