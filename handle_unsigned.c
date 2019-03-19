/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:54:22 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/19 16:31:14 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_uint_length(t_parser *p, va_list args)
{
	uintmax_t	nbr;

	nbr = va_arg(args, uintmax_t);
	if (p->f & UMAJ)
		return ((unsigned long)nbr);
	if (p->f & NONE)
		return ((unsigned int)nbr);
	else if (p->f & FLAGS_HH)
		return ((unsigned char)nbr);
	else if (p->f & FLAGS_LL)
		return ((unsigned long long)nbr);
	else if (p->f & FLAGS_H)
		return ((unsigned int)nbr);
	else if (p->f & FLAGS_L)
		return ((unsigned long)nbr);
	else if (p->f & FLAGS_J)
		return ((uintmax_t)nbr);
	else if (p->f & FLAGS_Z)
		return ((size_t)nbr);
	return (0);
}

void		append_uprefix(t_parser *p, char *buf, int *len)
{
	if (p->f & PREFIX)
	{
		if (p->base == 16)
			buf[(*len)++] = 'x';
		else if (p->base == 2)
			buf[(*len)++] = 'b';
		if (*len < BUF_SIZE)
			buf[(*len)++] = '0';
	}
	if (p->f & NEG)
		buf[(*len)++] = '-';
	else if (p->f & PLUS)
		buf[(*len)++] = '+';
	else if (p->f & SPACE)
		buf[(*len)++] = ' ';
	if (p->f & CAPSBASE)
		ft_strtoupper(buf);
}

void		handle_uprec(t_parser *p, char *buf, int *len)
{
	int		prefixlen;

	prefixlen = ft_strlen(get_prefix(p, p->format));
	while ((*len + prefixlen < p->precision) && (*len < BUF_SIZE))
		buf[(*len)++] = '0';
	if (!(p->f & LEFT_ALIGN))
	{
		if (p->width && (p->f & ZERO_FILL)
			&& (p->f & NEG || p->f & (PLUS | SPACE)))
			p->width--;
		while ((p->f & ZERO_FILL)
			&& (*len + prefixlen < p->width) && (*len < BUF_SIZE))
			buf[(*len)++] = '0';
	}
}

int			handle_unsigned(t_parser *p, va_list args)
{
	uintmax_t	nbr;
	char		buf[BUF_SIZE];
	int			len;
	int			ret;

	ret = 0;
	len = -1;
	nbr = get_uint_length(p, args);
	p->s = itoa_base_ulong(p, nbr, p->base, "0123456789abcdef");
	if (!nbr)
	{
		if (p->f & ZEROPREC && (p->format != 'o' || !(p->f & PREFIX)))
		{
			p->f &= ~ZERO_FILL;
			p->s = "";
		}
		p->f &= ~PREFIX;
	}
	while (p->s[++len])
		buf[len] = p->s[len];
	handle_uprec(p, buf, &len);
	append_uprefix(p, buf, &len);
	print_width(p, len, &ret, 0);
	print_buffer(buf, len, &ret);
	print_width(p, len, &ret, 1);
	if (p->s && !(p->f & ZEROPREC))
		free(p->s);
	return (ret);
}
