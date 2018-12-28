/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:36:58 by yoann             #+#    #+#             */
/*   Updated: 2018/12/28 17:28:40 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_int_length(t_parser *p, va_list args)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	if (p->f & NONE)
		return ((int)nbr);
	else if (p->f & FLAGS_HH)
		return ((char)nbr);
	else if (p->f & FLAGS_LL)
		return ((long long)nbr);
	else if (p->f & FLAGS_H)
		return((short)nbr);
	else if (p->f & FLAGS_L)
		return ((long)nbr);
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
	nbr = get_int_length(p, args);
	nb_str = itoa_base_long(p, nbr, p->base, "0123456789abcdef");
	while (nb_str[++len])
		buf[len] = nb_str[len];

	// ZERO FILL && !LEFT_ALIGN
	if (!(p->f & LEFT_ALIGN))
	{
		while (len < p->precision && len < BUFF_SIZE)
			buf[len++] = '0';
		while ((p->f & ZERO_FILL) && (len < p->width) && (len < BUFF_SIZE))
			buf[len++] = '0';
	}
	// SIGN
	if (len && len == p->width && ((p->f & NEG) || (p->f & PLUS) || (p->f & SPACE)))
		len--;
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


