/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_asm_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:47:41 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 18:16:36 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static void	ft_set_asm_options_bis(char c, t_option *options)
{
	if (c == 'B')
		options->q = 1;
	else if (c == 'D')
		options->w = 1;
	else if (c == 'H')
		options->r = 1;
	else if (c == 'S')
		options->y = 1;
}

void		ft_set_asm_options(char c, t_option *options)
{
	if (c == 'd')
		options->d = 1;
	else if (c == 'e')
		options->e = 1;
	else if (c == 'h')
		options->h = 1;
	else if (c == 'o')
		options->o = 1;
	else if (c == 'p')
		options->p = 1;
	else if (c == 's')
		options->s = 1;
	else if (c == 't')
		options->t = 1;
	else if (c == 'u')
		options->u = 1;
	else
		ft_set_asm_options_bis(c, options);
}
