/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:57:53 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/12 17:01:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_dell_inst(t_inst **inst)
{
	ft_strdel(&((*inst)->label	));
	ft_strdel(&((*inst)->opcode));
	free((*inst)->add);
	ft_dell_list_charlist(&(*inst)->param);
	free(*inst);
	*inst = NULL;
}
