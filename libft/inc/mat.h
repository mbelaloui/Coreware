/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:30:23 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/24 15:53:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT_H

# include "libft.h"

BOOL	ft_free_mat(char ***mat);
size_t	ft_matlen(char **mat);
void	ft_putmat(char **mat);
char	*ft_mat_to_str(char **mat, int pt);

#endif
