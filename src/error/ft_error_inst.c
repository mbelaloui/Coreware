/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_inst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:26:02 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/12 17:26:32 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_error_inst(int error)
{
	if (error == ERROR_INSTRUCTION)
		ft_printf("{red}Error instruction {eoc}\n");
	exit(error);
}
