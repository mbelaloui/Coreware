/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:10:46 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/22 12:11:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_champ(t_champ *champ)
{
	ft_printf("\nname {green}ok %s\n{eoc}", champ->name);
	ft_printf("\nsize {green} %d {eoc}\n", champ->size);
	ft_printf("\ncomment {green}ok %s\n{eoc}", champ->comment);
}
