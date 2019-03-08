/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:36:58 by yoann             #+#    #+#             */
/*   Updated: 2019/03/08 14:41:40 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_int_length(t_parser *p, va_list args)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	if (p->f & NONE)
	{
		if (p->f & UNSIGNED)
			return ((unsigned int)nbr);
		return ((int)nbr);
	}
	else if (p->f & FLAGS_HH)
		return ((char)nbr);
	else if (p->f & FLAGS_LL)
		return ((long long)nbr);
	else if (p->f & FLAGS_H)
		return((short)nbr);
	else if (p->f & FLAGS_L)
	{
		if (p->f & UNSIGNED)
			return ((unsigned long)nbr);
		return ((long)nbr);
	}
	else if (p->f & FLAGS_J)
		return (nbr);
	return (0);
}

int			handle_int(t_parser *p, va_list args)
{
	intmax_t	nbr;
	char		*nb_str;
	char		buf[BUF_SIZE];
	int			len;
	int			ret;
	int			i;

	ret = 0;
	len = -1;
	i = 0;
	nbr = get_int_length(p, args);
	nb_str = itoa_base_long(p, nbr, p->base, "0123456789abcdef");
	while (nb_str[++len])
		buf[len] = nb_str[len];
	while (len < p->precision && len < BUFF_SIZE)
			buf[len++] = '0';
	if (!(p->f & LEFT_ALIGN))
	{
		if (p->width && (p->f & ZERO_FILL) && (p->f & NEG || (p->f & (PLUS | SPACE))))
			p->width--;
		while ((p->f & ZERO_FILL) && (len + ft_strlen(p->prefix) < p->width) && (len < BUFF_SIZE))
			buf[len++] = '0';
	}
	if (p->f & PREFIX && nbr)
	{
		while (p->prefix[i])
		{
			buf[len] = p->prefix[i];
			len++;
			i++;
		}
	}
	// SIGN
	// if (p->f & ZERO_FILL && len && len == p->width && ((p->f & NEG) || (p->f & PLUS) || (p->f & SPACE)))
	// 	len--;
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


