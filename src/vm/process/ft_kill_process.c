/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 10:20:40 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 10:32:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static t_process	*dell_bgn(t_process **pt)
{
	t_process *to_kill;

	to_kill = *pt;
	*pt = (*pt)->next;
	free(to_kill);
	return (*pt);
}

static t_process	*dell_elem(t_process **pt)
{
	t_process *to_kill;

	to_kill = *pt;
	*pt = (*pt)->next;
	free(to_kill);
	return (*pt);
}

t_process			*ft_kill_process(t_process *list_process)
{
	t_process *head;
	t_process *pt;
	t_process *save;

	head = list_process;
	pt = head;
	save = NULL;
	while (pt)
	{
		if (!pt->a_live && !save)
			head = dell_bgn(&pt);
		else if (!pt->a_live)
		{
			pt = dell_elem(&pt);
			if (save)
				save->next = pt;
		}
		else
		{
			save = pt;
			pt = pt->next;
		}
	}
	return (head);
}
