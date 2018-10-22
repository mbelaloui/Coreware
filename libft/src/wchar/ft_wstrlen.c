/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:51:28 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 15:56:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t		ft_wstrlen(const wchar_t *str)
{
	wchar_t *temp;

	temp = (wchar_t *)str;
	while (*str)
		++str;
	return (str - temp);
}
