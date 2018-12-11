/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:10:34 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/11 19:32:19 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_parser *p, char *format)
{
	while (*format)
	{
		if (*format == '-')
			p->left_justify = 1;
		else if (*format == '+')
			p->plus = 1;
		else if (*format == ' ')
			p->space = 1;
		else if (*format == '0')
			p->zero_padded = 1;
		format++;
	}
}

int		process(va_list args, char *format)
{
	int		ret;
	t_parser	*p;

	p = malloc(sizeof(t_parser));
	ret = 0;
	while (*format)
	{
		ft_putchar(*format);
		if (*format == '%')
		{
			format++;
			parse_flags(p, format);
		}
		format++;
		ret++;
	}
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

int		main()
{
	ft_printf("salut", "1", "2", "3");
	return (0);
}