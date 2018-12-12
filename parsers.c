/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:53:03 by yoann             #+#    #+#             */
/*   Updated: 2018/12/12 20:31:51 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_parser *p, char **format)
{
	(*format)++;
	while (ft_strpbrk(*format, "-+ 0#"))
	{
		if (**format == '-')
			p->left_justify = 1;
		else if (**format == '+')
			p->plus = 1;
		else if (**format == ' ')
			p->space = 1;
		else if (**format == '0')
			p->zero_padded = 1;
		else if (**format == '#')
			p->prefix = 1;
		(*format)++;
	}
	if (p->left_justify)
		p->zero_padded = 0;
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

int		parse_length(t_parser *p, char **format)
{
	if (ft_strpbrk(*format, "hl"))
	{
		if (**format == 'h')
		{
			if (*(*format + 1) == 'h')
			{
				*format += 2;
				p->l |= HH;
			}
			else
			{
				*format += 1;
				p->l |= H;
			}
		}
		if (**format == 'l')
		{
			if (*(*format + 1) == 'l')
			{
				*format += 2;
				p->l |= LL;
			}
			else
			{
				*format += 1;
				p->l |= L;
			}
		}
	}
	if (!p->l)
		p->l |= NONE;
	return (1);
}
