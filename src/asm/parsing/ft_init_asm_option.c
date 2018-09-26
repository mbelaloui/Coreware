/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_asm_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:55:55 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 12:11:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	ft_init_asm_option(t_option *op)
{
	op->B = 0;
	op->D = 0;
	op->d = 0;
	op->e = 0;
	op->h = 0;
	op->H = 0;
	op->o = 0;
	op->m = 0;
	op->p = 0;
	op->s = 0;
	op->S = 0;
	op->u = 0;
	op->t = 0;
}
