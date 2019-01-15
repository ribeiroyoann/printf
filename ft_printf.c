/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:10:34 by yoribeir          #+#    #+#             */
/*   Updated: 2019/01/15 18:32:27 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_parser(t_parser *p)
{
	p->width = 0;
	p->precision = 0;
	p->f = 0;
	p->base = 0;
}

int		parser(t_parser *p, char **format)
{
	parse_flags(p, format);
	parse_width(p, format);
	parse_precision(p, format);
	parse_length(p, format);
	p->base = get_base(p, **format);
	p->prefix = get_prefix(p, **format);
	if (**format == 'u')
		p->f &= ~(PLUS | SPACE);
	if (p->precision > 0)
		p->f &= ~ZERO_FILL;
	return (0);
}

int		process(va_list args, const char *format)
{
	int			ret;
	t_parser	*p;
	t_jumptable	jt;

	p = malloc(sizeof(t_parser));
	init_parser(p);
	ret = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			parser(p, (char **)&format);
			jt = init_table(*format);
			if (jt)
				ret += jt(p, args);
			init_parser(p);
		}
		else
		{
			ft_putchar(*format);
			ret++;
		}
		format++;
	}
	printf(" %d\n", ret);
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
	printf(" %d\n", printf("%x", -42));
	printf("\n--------\n");
	ft_printf("%x", -42);

	return (0);
}