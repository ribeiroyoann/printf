/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:53:03 by yoann             #+#    #+#             */
/*   Updated: 2019/01/16 14:59:37 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_parser *p, char **format)
{
	(*format)++;
	while (**format == '-' || **format == '+' || **format == ' ' || **format == '0'
		|| **format == '#')
	{
		if (**format == '-')
			p->f |= LEFT_ALIGN;
		else if (**format == '+')
			p->f |= PLUS;
		else if (**format == ' ')
			p->f |= SPACE;
		else if (**format == '0')
			p->f |= ZERO_FILL;
		else if (**format == '#')
			p->f |= PREFIX;
		(*format)++;
	}
	if (p->f & LEFT_ALIGN)
		p->f &= ~ZERO_FILL;
	if (p->f & PLUS)
		p->f &= ~SPACE;
	return (1);
}

int		parse_width(t_parser *p, char **format)
{
	int		ret;

	ret = 0;
	while (ft_isdigit(**format))
	{
		ret = ret * 10 + (**format - '0');
		(*format)++;
	}
	p->width = ret;
	return (1);
}

int		parse_precision(t_parser *p, char **format)
{
	int		ret;

	ret = 0;
	if (**format == '.')
	{
		p->f |= PRECISION;
		(*format)++;
		while (ft_isdigit(**format))
		{
			ret = ret * 10 + (**format - '0');
			(*format)++;
		}
	}
	p->precision = ret;
	return (1);
}

void	parse_length(t_parser *p, char **format)
{
	if (**format == 'l')
	{
		(*format)++;
		p->f |= FLAGS_L;
		if (**format == 'l')
		{
			p->f |= FLAGS_LL;
			(*format)++;
		}
	}
	else if (**format == 'h')
	{
		(*format)++;
		p->f |= FLAGS_H;
		if (**format == 'h')
		{
			p->f |= FLAGS_HH;
			(*format)++;
		}
	}
	else if (**format == 'j')
	{
		(*format)++;
		p->f |= FLAGS_J;
	}
	else
		p->f |= NONE;
}

char	*get_prefix(t_parser *p, char c)
{
	if (!(p->f & PREFIX))
		return ("");
	if (c == 'o')
		return ("0");
	else if (c == 'x')
		return ("x0");
	else if (c == 'X')
		return ("X0");
	else
		return ("");
}