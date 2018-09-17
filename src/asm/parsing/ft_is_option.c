/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:28:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 15:41:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

BOOL	ft_is_option(const char option)
{
	if (option == 'B'
			|| option == 'd'
			|| option == 'D'
			|| option == 'e'
			|| option == 'h'
			|| option == 'H'
			|| option == 'm'
			|| option == 'o'
			|| option == 'p'
			|| option == 's'
			|| option == 'S'
			|| option == 't'
			|| option == 'u')
		return (T);
	return (F);
}
