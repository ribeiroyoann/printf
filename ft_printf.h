/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:57:50 by yoribeir          #+#    #+#             */
/*   Updated: 2019/01/16 15:28:47 by yoribeir         ###   ########.fr       */
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

#define NONE		(1 << 5)
#define FLAGS_HH	(1 << 6)
#define FLAGS_H		(1 << 7)
#define FLAGS_L		(1 << 8)
#define FLAGS_LL	(1 << 9)
#define	FLAGS_J		(1 << 10)

#define NEG			(1 << 11)
#define CAPSBASE	(1 << 12)
#define UNSIGNED	(1 << 13)
#define PRECISION	(1 << 14)
#define ZERO		(1 << 15)

#define BUF_SIZE 21

typedef	struct	s_parser
{
	int			width;
	int			precision;
	int			len;
	int			base;
	short		f;
	char		*prefix;
}				t_parser;

typedef		int (*t_jumptable)(t_parser *p, va_list args);
int			ft_printf(const char *format, ...);

/*
** -------- PARSERS --------
*/

int		parse_flags(t_parser *p, char **format);
int		parse_width(t_parser *p, char **format);
int		parse_precision(t_parser *p, char **format);

void	parse_length(t_parser *p, char **format);
char	*get_prefix(t_parser *p, char c);

/*
** -------- HANDLERS --------
*/

t_jumptable	init_table(char c);
intmax_t	get_int_length(t_parser *p, va_list args);
int			handle_int(t_parser *p, va_list args);
int			handle_octal(t_parser *p, va_list args);
int			handle_char(t_parser *p, va_list args);
int			handle_pointer(t_parser *p, va_list args);
int			handle_escape(t_parser *p, va_list args);
int			handle_string(t_parser *p, va_list args);

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

char *toUpper(char *str);
char    *ft_strrev(char *str);
#endif
