/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:23:41 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/17 12:25:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"
char	*ft_get_vm_comment(int fd)
{
	unsigned char oct[4]	;
	char *comment;
	char *temp;
	int byt;

	byt = 0;
	comment = NULL;
	while(byt < (PROG_COMMENT_LENGTH / 4))
	{
		ft_bzero(&oct, sizeof(oct));
		if (!ft_get_next_oct(fd, &oct))
		{
			ft_printf("{red}Error reading file"
					"<comment part> reaching unexpecting eof 3\n{eoc}");
			ft_printf("{red}Error while reading name Ko\n{eoc}");
			exit(0);
		}
		//if (t % 2)
		////ft_printf("\n");
		////ft_put_oct(r);
		temp = ft_u_str_to_str(oct);
		comment = ft_strjoin_clear(&comment, &temp, BOTH);
		byt++;
	}
	return (comment);
}

