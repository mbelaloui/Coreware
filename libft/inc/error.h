/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:35:20 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/03 12:36:58 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_NOT_ENOUGH_MEM       1
# define ERROR_CAN_NOT_OPEN_FILE    2
# define ERROR_CAN_NOT_CEART_FILE   3

void	ft_error_exe(int id_error);

#endif
