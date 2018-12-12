/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:57:50 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/12 19:35:51 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

enum		length
	{
		NONE, HH, H, L, LL
	};

#define NONE	(1 << 0)
#define HH		(1 << 1)
#define H		(1 << 2)
#define L		(1 << 3)
#define LL		(1 << 4)

typedef	struct	s_parser
{
	int			left_justify;
	int			space;
	int			plus;
	int			zero_padded;
	int			prefix;
	int			width;
	int			precision;
	unsigned	char	l;

}				t_parser;

typedef		int (*t_jumptable)(t_parser *p, va_list args);

/*
** -------- PARSERS --------
*/

int		parse_flags(t_parser *p, char **format);
int		parse_width(t_parser *p, char **format);
int		parse_precision(t_parser *p, char **format);
int		parse_length(t_parser *p, char **format);

/*
** -------- HANDLERS --------
*/

int		handle_int(t_parser *p, va_list args);

/*
** UTILS
*/

char	*ft_strpbrk(const char *s1, const char *s2);
void	print_parser(t_parser *p);
void	printBits(size_t const size, void const * const ptr);

#endif
