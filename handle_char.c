/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:38:56 by yoann             #+#    #+#             */
/*   Updated: 2019/03/07 13:33:13 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_char(t_parser *p, va_list args)
{
	char		chr;
	char		buf[BUF_SIZE];
	int			len;
	int			ret;
	int			i;

	ret = 0;
	len = 1;
	chr = (char)va_arg(args, int);
	buf[0] = chr;

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
