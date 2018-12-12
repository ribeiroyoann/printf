/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:10:34 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/12 19:17:33 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parser(t_parser *p, char **format)
{
	parse_flags(p, format);
	// printf("1[%c]\n", **format);
	parse_width(p, format);
	// printf("2[%c]\n", **format);
	parse_precision(p, format);
	// printf("3[%c]\n", **format);
	parse_length(p, format);
	printf("4[%c]\n", **format);
	return (0);
}

int		process(va_list args, const char *format)
{
	int			ret;
	t_parser	*p;

	p = malloc(sizeof(t_parser));
	p->l = 0;
	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			parser(p, (char **)&format);
			// ret = handler(args, )
		}
		ft_putchar(*format);
		format++;
		ret++;
	}
	print_parser(p);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	ret = process(args, format);
	va_end(args);
	return (ret);
}

int		main(int argc, char **argv)
{
	// printf("%5d\n", 42);
	ft_printf("%dsalut");
	return (0);
}