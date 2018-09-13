/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:36:23 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 14:37:10 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_put_option(t_option *option)
{
	ft_printf(" B = [%s]  \n", (option->B) ? "ok" : "--	");
	ft_printf(" D = [%s]  \n", (option->D) ? "ok" : "--");
	ft_printf(" h = [%s]  \n", (option->h) ? "ok" : "--");
	ft_printf(" H = [%s]  \n", (option->H) ? "ok" : "--");
	ft_printf(" o = [%s]  \n", (option->o) ? "ok" : "--");
	ft_printf(" p = [%s]  \n", (option->p) ? "ok" : "--");
	ft_printf(" s = [%s]  \n", (option->s) ? "ok" : "--");
	ft_printf(" u = [%s]  \n", (option->u) ? "ok" : "--");
}
