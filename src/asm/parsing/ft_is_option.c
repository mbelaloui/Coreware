/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:28:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 14:32:09 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

BOOL     ft_is_option(const char option)
{
	if (option == 'B' || option == 'D' || option == 'h'
			|| option == 'd' || option == 'e' || option == 'H' || option == 'o'
			|| option == 'p'
			|| option == 't'  || option == 's' || option == 'S'
			|| option == 'u')
		return (T);
	return (F);
}
