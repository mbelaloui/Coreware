/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcule_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:08:17 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 15:08:40 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int			ft_calcule_add(int val, int pc)
{
	int ret;

	ret = (val % IDX_MOD) + pc;
	return ((ret < 0) ? ((MEM_SIZE + ret) % MEM_SIZE) : (ret % MEM_SIZE));
}