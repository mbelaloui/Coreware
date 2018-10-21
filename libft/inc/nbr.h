/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:53:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 14:47:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_H
# define NBR_H

# include "list.h"

intmax_t		ft_abs(const intmax_t nbr);
int				ft_atoi(const char *str);
intmax_t		ft_atointmax(const char *str);
long			ft_atoi_v1(const char *str);
long			ft_atoi_v2(const char *str);
long			ft_atoi_v3(const char *str);
intmax_t		ft_base_to_decimal(const char *str, const int str_base);
intmax_t		ft_base_to_decimal_v2(const char *str, const int str_base);
intmax_t		ft_base_to_decimal_v3(const char *str, const int str_base);

char			*ft_decimal_to_base_dynm(const intmax_t nbr_in, int base,
		int form);
void			ft_decimal_to_base_stat(char *tab_ret, const intmax_t nbr,
		const int base, const int form);

void			ft_udecimal_to_base_stat(char *tab_ret, const uintmax_t nbr,
		const int base, const int form);

int				ft_get_char_base(const char nbr);
int				ft_get_len_value_base(const intmax_t nbr, const int exit_base);
int				ft_get_len_value_ubase(const uintmax_t nbr,
		const int exit_base);
char			*ft_get_mask(int id_mask, char *oct);
char			ft_intochar(const int nbr);

int				ft_is_elem_base(const char c, const int base);
BOOL			ft_is_overflow_intmax(char *param);

intmax_t		ft_max(const intmax_t a, const intmax_t b);
intmax_t		ft_min(const intmax_t a, const intmax_t b);

void			ft_swap_int(intmax_t *a, intmax_t *b);

short			ft_nbrlen(intmax_t nbr);
short			ft_unbrlen(uintmax_t nbr);

void			ft_putnbr(intmax_t nb);
void			ft_putnbr_fd(intmax_t n, int fd);

BOOL			ft_isnumerique(char *str);
int				ft_byts_to_int(unsigned char b[4]);

unsigned char	*ft_int_to_byts(int val, int size);

#endif
