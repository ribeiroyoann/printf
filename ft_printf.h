/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:57:50 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/21 18:52:01 by yoribeir         ###   ########.fr       */
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



#define	LEFT_ALIGN	(1 << 0)
#define	SPACE 		(1 << 1)
#define	PLUS		(1 << 2)
#define	ZERO_FILL	(1 << 3)
#define	PREFIX		(1 << 4)

#define NONE	(1 << 5)
#define HH		(1 << 6)
#define H		(1 << 7)
#define L		(1 << 8)
#define LL		(1 << 9)

#define NEG		(1 << 11)
#define MINBASE		(1 << 12)

#define BUF_SIZE 21

typedef	struct	s_parser
{
	int			width;
	int			precision;
	int			len;
	int			base;
	short		f;
}				t_parser;

typedef		int (*t_jumptable)(t_parser *p, va_list args);
int			ft_printf(const char *format, ...);

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

t_jumptable	init_table(char c);
intmax_t	get_int_length(t_parser *p, va_list args);
int			handle_int(t_parser *p, va_list args);
int			handle_octal(t_parser *p, va_list args);
int			handle_char(t_parser *p, va_list args);
int			handle_pointer(t_parser *p, va_list args);

/*
** UTILS
*/

char	*ft_strpbrk(const char *s1, const char *s2);
void	print_parser(t_parser *p);
void	printBits(size_t const size, void const * const ptr);

char                *ft_itoa1(t_parser *p, int n);
char                *itoa_base(t_parser *p, int n, int base);
char                *itoa_base_long(t_parser *p, long long n, int base, char *s_base);
int    			 	get_base(t_parser *p, char c);

#endif
