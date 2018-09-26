/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:36:23 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 16:53:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	ft_put_option(t_option *option)
{
	ft_printf(" B = [%s]  \n", (option->q) ? "ok" : "--");
	ft_printf(" d = [%s]  \n", (option->d) ? "ok" : "--");
	ft_printf(" D = [%s]  \n", (option->w) ? "ok" : "--");
	ft_printf(" e = [%s]  \n", (option->e) ? "ok" : "--");
	ft_printf(" h = [%s]  \n", (option->h) ? "ok" : "--");
	ft_printf(" H = [%s]  \n", (option->r) ? "ok" : "--");
	ft_printf(" o = [%s]  \n", (option->o) ? "ok" : "--");
	ft_printf(" p = [%s]  \n", (option->p) ? "ok" : "--");
	ft_printf(" s = [%s]  \n", (option->s) ? "ok" : "--");
	ft_printf(" S = [%s]  \n", (option->y) ? "ok" : "--");
	ft_printf(" t = [%s]  \n", (option->t) ? "ok" : "--");
	ft_printf(" u = [%s]  \n", (option->u) ? "ok" : "--");
}
