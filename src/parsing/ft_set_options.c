/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:12:51 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/26 12:13:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

/*
** else if (c == '')
*/

void	ft_set_options(char c, unsigned long *op)
{
	if (c == 'o')
		(*op) = (*op) | MASK_OP_O;
	else if (c == 'a')
		(*op) = (*op) | MASK_OP_A;
}