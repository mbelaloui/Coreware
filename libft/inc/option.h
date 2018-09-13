/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:39:51 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/12 17:09:27 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  structurer les fonction pour recupere les options
*/

#ifndef OPTION_H
# define OPTION_H
#include "libft.h"

typedef struct	s_option
{
	int			B : 1;
	int			D : 1;
	int			d : 1;
	int			e : 1;
	int			H : 1;
	int			h : 1;
	int			o : 1;
	int			p : 1;
	int			s : 1;
	int			S : 1;
	int			t : 1;
	int			u : 1;
}				t_option;

void			ft_init_option(t_option *op);
void			ft_error_option(int id_error, char *name, t_option *op, char c);
BOOL			ft_extract_options(char *param, t_option *options, char *name);

#endif
