/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:30:23 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/14 17:54:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT_H

# include "libft.h"

void	ft_free_mat(char ***mat);
size_t	ft_matlen(char **mat);
void	ft_putmat(char **mat);
char	*ft_mat_to_str(char **mat, int pt);

#endif
