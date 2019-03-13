/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:54:22 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/13 19:11:32 by yoribeir         ###   ########.fr       */
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
		return((unsigned int)nbr);
	else if (p->f & FLAGS_L)
		return ((unsigned long)nbr);
	else if (p->f & FLAGS_J)
		return ((uintmax_t)nbr);
	else if (p->f & FLAGS_Z)
		return ((size_t)nbr);
	return (0);
}

int			handle_unsigned(t_parser *p, va_list args)
{
	uintmax_t	nbr;
	char		*nb_str;
	char		buf[BUF_SIZE];
	int			len;
	int			ret;
	int			i;

	ret = 0;
	len = -1;
	i = 0;
	nbr = get_uint_length(p, args);
	nb_str = itoa_base_ulong(p, nbr, p->base, "0123456789abcdef");
	if (!nbr)
		p->f &= ~PREFIX;
	while (nb_str[++len])
		buf[len] = nb_str[len];
	while ((len < p->precision) && (len < BUF_SIZE))
		buf[len++] = '0';
	if (!(p->f & LEFT_ALIGN))
	{
		if (p->width && (p->f & ZERO_FILL) && (p->f & NEG || p->f & (PLUS | SPACE)))
			p->width--;
		while ((p->f & ZERO_FILL) && (len + ft_strlen(get_prefix(p, p->format)) < p->width) && (len < BUF_SIZE))
			buf[len++] = '0';
	}
	// len > 1 || len for "%#1x, 1"
	if (p->f & PREFIX)
	{
		// if (!(p->f & PRECISION) && len > 1 && ((len == p->precision) || (len == p->width)))
		// {
		// 	// len--;
		// 	// if (len && (p->base == 16))
		// 		// len--;
		// }
		if (p->base == 16)
			buf[len++] = 'x';
		else if (p->base == 2)
			buf[len++] = 'b';
		if (len < BUF_SIZE)
			buf[len++] = '0';
	}
	if (p->f & NEG)
		buf[len++] = '-';
	else if (p->f & PLUS)
		buf[len++] = '+';
	else if (p->f & SPACE)
		buf[len++] = ' ';

	//BASIC WIDTH
	i = len;
	if (!(p->f & LEFT_ALIGN) && !(p->f & ZERO_FILL))
	{
			while (i < p->width)
			{
				ft_putchar(' ');
				i++;
				ret++;
			}
	}
	//TO UPPER FOR X
	if (p->f & CAPSBASE)
		toUpper(buf);
	//PRINT BUF
  	i = 0;
  	while (i < len)
  	{
  		ft_putchar(buf[len - i - 1]);
  		i++;
  		ret++;
  	}
  	//LEFT JUSTIFY
  	if (p->f & LEFT_ALIGN)
  	{
  		while (i < p->width)
  		{
  			ft_putchar(' ');
  			ret++;
  			i++;
  		}
  	}
	return (ret);
}