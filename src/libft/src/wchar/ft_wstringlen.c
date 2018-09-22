/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstringlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:10:23 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 15:56:34 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wchar.h"

size_t		ft_wstringlen(const wchar_t *str)
{
	size_t cp;

	cp = 0;
	while (*str)
	{
		cp += ft_wcharlen(*str);
		++str;
	}
	return (cp);
}
