/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:55:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 15:06:11 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include "printf.h"

void	*ft_gettabcolor(void (*put_colors[8])());
void	ft_setblue();
void	ft_set_i_blue(void);

void	ft_setcyan();
void	ft_set_i_cyan(void);

void	ft_setgreen();
void	ft_set_i_green(void);

void	ft_setmagenta();
void	ft_set_i_magenta(void);

void	ft_setred();
void	ft_set_i_red(void);

void	ft_setwhite();
void	ft_set_i_white(void);

void	ft_setyellow();
void	ft_set_i_yellow(void);

void	ft_inittabcolor(char **colors);
int		ft_put_color(char *str, int pt);
int		ft_get_color(char *str);

#endif
