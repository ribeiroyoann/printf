/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:10:34 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/28 17:18:51 by yoann            ###   ########.fr       */
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
	parse_length2(p, format);
	p->base = get_base(p, **format);
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
	printf(" %d\n", printf("[%d]", 17));
	printf("\n--------\n");
	ft_printf("[%d]", 17);

	return (0);
}