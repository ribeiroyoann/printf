/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:53:03 by yoann             #+#    #+#             */
/*   Updated: 2018/12/28 17:25:54 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_parser *p, char **format)
{
	(*format)++;
	while (ft_strpbrk(*format, "-+ 0#"))
	{
		if (ft_isdigit(**format) && **format != '0')
			break ;
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
	if (**format == 'h')
	{
		(*format)++;
		p->f |= FLAGS_H;
		if (**format == 'h')
		{
			p->f |= FLAGS_HH;
			(*format)++;
		}
	}
	if (**format == 'j')
	{
		(*format)++;
		p->f |= FLAGS_J;
	}
	else
		p->f |= NONE;
}
