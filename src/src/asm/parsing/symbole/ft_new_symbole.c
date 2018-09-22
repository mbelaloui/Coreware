/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_symbole.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:20:51 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 13:25:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

t_symbole	*ft_new_symbole(char *sym, int add)
{
	t_symbole *ret;

	ret = malloc(sizeof(*ret));
	ret->data = ft_strdup(sym);
	ret->add = add;
	ret->used = F;
	ret->next = NULL;
	return (ret);
}
