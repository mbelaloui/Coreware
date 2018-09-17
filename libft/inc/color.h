/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:55:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:45:36 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include "printf.h"

void	*ft_gettabcolor(void (*put_colors[8])());
void	ft_setblue();
void	ft_setcyan();
void	ft_setgreen();
void	ft_setmagenta();
void	ft_setred();
void	ft_setwhite();
void	ft_setyellow();
void	ft_inittabcolor(char **colors);
int		ft_put_color(char *str, int pt);
int		ft_get_color(char *str);

#endif
