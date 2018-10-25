/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettabcolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:56:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 15:06:01 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/color.h"

void	*ft_gettabcolor(void (*put_colors[9])())
{
	put_colors[0] = &ft_setblue;
	put_colors[1] = &ft_setcyan;
	put_colors[2] = &ft_setwhite;
	put_colors[3] = &ft_setgreen;
	put_colors[4] = &ft_setmagenta;
	put_colors[5] = &ft_setred;
	put_colors[6] = &ft_setwhite;
	put_colors[7] = &ft_setyellow;
	put_colors[8] = &ft_set_i_blue;
	put_colors[9] = &ft_set_i_cyan;
	put_colors[10] = &ft_set_i_green;
	put_colors[11] = &ft_set_i_magenta;
	put_colors[12] = &ft_set_i_red;
	put_colors[13] = &ft_set_i_white;
	put_colors[14] = &ft_set_i_yellow;
	return (put_colors);
}
