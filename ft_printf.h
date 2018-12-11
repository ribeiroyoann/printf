/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:57:50 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/11 19:28:24 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
#include <stdio.h>

typedef	struct	s_parser
{
	int			left_justify;
	int			space;
	int			plus;
	int			zero_padded;
	int			width;
}				t_parser;

#endif
