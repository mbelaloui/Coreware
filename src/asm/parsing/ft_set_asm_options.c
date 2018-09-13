/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_asm_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:47:41 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 14:47:42 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	ft_set_asm_options(char c, t_option *options)
{
	if (c == 'B')
		options->B = 1;
	else if (c == 'D')
		options->D = 1;
	else if (c == 'd')
		options->d = 1;
	else if (c == 'e')
		options->e = 1;
	else if (c == 'h')
		options->h = 1;
	else if (c == 'H')
		options->H = 1;
	else if (c == 'o')
		options->o = 1;
	else if (c == 'p')
		options->p = 1;
	else if (c == 's')
		options->s = 1;
	else if (c == 'S')
		options->S = 1;
	else if (c == 'u')
		options->u = 1;
	else if (c == 't')
		options->t = 1;
}
