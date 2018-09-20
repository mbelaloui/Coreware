/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:43:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 16:26:29 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../inc/vm.h"

int		ft_error_exe(int error)
{
	ft_printf("{red}Error execution{eoc}");
	if (error == ERROR_NOT_ENOUGH_MEM)
		ft_printf("not enough memory for malloc\n");
/*	else if (error == ERROR_SIZE_FILE)
	{
		ft_printf("the size of the champions must be less than "
				"%d\n",CHAMP_MAX_SIZE);
	}
*/
	exit(error);
}
