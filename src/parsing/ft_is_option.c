/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:12:07 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/29 14:56:04 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_option(const char option)
{
	if (option == 'o' || option == 'a')// || option == 'l' || option == 'm'
		return (T);
	return (F);
}