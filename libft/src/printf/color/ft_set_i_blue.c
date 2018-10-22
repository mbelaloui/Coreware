/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_i_blue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:08:59 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 15:10:08 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/color.h"

void	ft_set_i_blue(void)
{
	char	*str;
	int		pt;

	pt = -1;
	str = "\033[30;44m";
	while (str[++pt])
		ft_put_buf(str[pt], ING);
}
