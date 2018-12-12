/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:57:50 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/12 14:10:19 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

typedef	struct	s_parser
{
	int			left_justify;
	int			space;
	int			plus;
	int			zero_padded;
	int			prefix;
	int			width;
	int			precision;
}				t_parser;


/*
** PARSERS
*/

int		parse_flags(t_parser *p, char **format);
int		parse_width(t_parser *p, char **format);
int		parse_precision(t_parser *p, char **format);

/*
** UTILS
*/

char	*ft_strpbrk(const char *s1, const char *s2);
void	print_parser(t_parser *p);

#endif
