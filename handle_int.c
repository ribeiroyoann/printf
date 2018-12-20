/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:36:58 by yoann             #+#    #+#             */
/*   Updated: 2018/12/20 15:37:47 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_int_length(t_parser *p, va_list args)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	if (p->f & NONE)
		return ((int)nbr);
	else if (p->f & HH)
		return ((char)nbr);
	else if (p->f & H)
		return((short)nbr);
	else if (p->f & L)
		return ((long)nbr);
	else if (p->f & LL)
		return ((long long)nbr);
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
	nb_str = itoa_base(p, nbr, p->base);
	while (nb_str[++len])
		buf[len] = nb_str[len];

	// ZERO FILL && !LEFT_ALIGN
	if (!(p->f & LEFT_ALIGN))
	{
		while ((p->f & ZERO_FILL) && (len < p->width) && (len < BUFF_SIZE))
			buf[len++] = '0';
	}
	// SIGN
	if (len && len == p->width && p->f & NEG)
		len--;
	if (p->f & NEG)
		buf[len++] = '-';

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


