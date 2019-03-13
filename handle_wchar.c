/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:57:41 by yoann             #+#    #+#             */
/*   Updated: 2019/03/13 18:33:09 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

int		ft_putwchar(wchar_t chr)
{
	if (chr <= 0x7F)
	{
		ft_putchar(chr);
		return (1);
	}
	else if (chr <= 0x7FF)
	{
		ft_putchar((chr >> 6) + 0xC0);
		ft_putchar((chr & 0x3F) + 0x80);
		return (2);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar((chr >> 12) + 0xE0);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
		return (3);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar((chr >> 18) + 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) + 0x80);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
		return (4);
	}
	return (-1);
}

int		wcharlen(wchar_t chr)
{
	if (chr <= 0x7F)
		return (1);
	else if (chr <= 0x7FF)
		return (2);
	else if (chr <= 0xFFFF)
		return (3);
	else if (chr <= 0x10FFFF)
		return (4);
	return (0);
}

int		handle_wchar(t_parser *p, va_list args)
{
	wchar_t		chr;
	int			ret;
	int			len;
	int			i;

	(void)p;
	ret = 0;
	chr = va_arg(args, wchar_t);
	len = wcharlen(chr);
	i = len;
	if (!(p->f & LEFT_ALIGN) && !(p->f & ZERO_FILL))
	{
		while (i++ < p->width)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	ret += ft_putwchar(chr);
	if (p->f & LEFT_ALIGN)
	{
		while (i++ < p->width)
		{
			ft_putchar(' ');
		}
	}
	return (ret);
}

size_t	ft_wstrlen(const int *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			handle_wstring(t_parser *p, va_list args)
{
	int		*str;
	int		len;
	int		i;

	i = 0;
	str = va_arg(args, int*);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_wstrlen(str);
	if (p->f & PRECISION)
		len = (len < p->precision ? len : p->precision);
	if (!(p->f & LEFT_ALIGN))
	{
		while (len < p->width)
		{
			ft_putchar(' ');
			i++;
			len++;
		}
	}
	while ((*str && (!(p->f & PRECISION) || p->precision--)))
	{
		ft_putwchar(*str);
		str++;
		i++;
	}
	if (p->f & LEFT_ALIGN)
	{
		while (len < p->width)
		{
			ft_putchar(' ');
			len++;
			i++;
		}
	}
	return (i);
}
