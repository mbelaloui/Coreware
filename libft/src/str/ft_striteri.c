/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 07:21:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:38:09 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	size_t pt;

	pt = 0;
	if (!f || !str)
		return ;
	while (*str)
	{
		f((unsigned int)pt, str++);
		pt++;
	}
}
