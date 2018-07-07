/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:36:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 10:51:46 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include "libft.h"

void	ft_bzero(void *str, size_t size);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dest, const void *src, int c, size_t max_size);
void	*ft_memchr(const void *str, int c, size_t max_size);
int		ft_memcmp(const void *str1, const void *str2, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	ft_memdel(void **mem);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *mem, int c, size_t size);

#endif
