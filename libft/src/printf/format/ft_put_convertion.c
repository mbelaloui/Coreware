/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_convertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 05:10:51 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:35:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

void	ft_put_convertion(t_convert *convertion)
{
	if (convertion)
	{
		ft_putstr("-5- print convertion value :\n\t- h ->\t");
		ft_putnbr((convertion->h) ? 1 : 0);
		ft_putstr("\t- value h ->\t");
		ft_putnbr(convertion->nbr_h % 2);
		ft_putstr("\n\t- l ->\t");
		ft_putnbr((convertion->l) ? 1 : 0);
		ft_putstr("\t- value l ->\t");
		ft_putnbr(convertion->nbr_l % 2);
		ft_putstr("\n\t- j ->\t");
		ft_putnbr((convertion->j) ? 1 : 0);
		ft_putstr("\n\t- z ->\t");
		ft_putnbr((convertion->z) ? 1 : 0);
		ft_putstr("\n");
	}
	else
		ft_putstr("flags is NULL\n");
}
