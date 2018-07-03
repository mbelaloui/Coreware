/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:52:06 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/03 17:03:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define UPPER			 1
# define LOWER			 0

# define DONT_CLEAN		 0
# define CLEAN_FIRST	 1
# define CLEAN_LAST		 2
# define CLEAN_BOTH		 3

# define WHITE			"\x1B[0m"
# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define MAGENTA		"\x1B[35m"
# define CYAN			"\x1B[36m"

# define MAX_INT		 2147483647
# define MIN_INT		-2147483648

# define MAX_U_LONG		 4294967296

# define MAX_INTMAX		 9223372036854775807
# define MIN_INTMAX		-9223372036854775807

# define SIZE_BUF_SHOW	 4096
# define SIZE_BUF		 65
# define EOL			 0
# define PUT_CHAR		 1
# define RESET			-1
# define ING			 2
# define LEN_BUF		 3
# define CLEAN_BUF		 4

# define BIN			 2
# define OCT			 8
# define DEC			 10
# define EXA			 16

# define SIZE_TAB_CONV	 128

# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <wchar.h>
# include <inttypes.h>
# include "bool.h"

# include "char.h"
# include "charlist.h"
# include "color.h"
# include "file.h"
# include "list.h"
# include "lst.h"
# include "mat.h"
# include "mem.h"
# include "nbr.h"
# include "str.h"
# include "printf.h"
# include "tab.h"
# include "sys.h"
# include "wchar.h"

#endif
