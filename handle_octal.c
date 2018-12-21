/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:44:15 by yoann             #+#    #+#             */
/*   Updated: 2018/12/21 19:22:10 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_octal(t_parser *p, va_list args)
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
	nb_str = itoa_base(p, nbr, 8);
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
			while (i++ < p->width)
			{
				ft_putchar(' ');
				ret++;
			}
	}
  	i = 0;
  	while (i < len)
  	{
  		ft_putchar(buf[len - i - 1]);
  		i++;
  		ret++;
  	}
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
