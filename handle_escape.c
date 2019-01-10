/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:09:41 by yoribeir          #+#    #+#             */
/*   Updated: 2019/01/10 13:16:00 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_escape(t_parser *p, va_list args)
{
	char		buf[BUF_SIZE];
	int			len;
	int			ret;
	int			i;

	ret = 0;
	len = 1;
	buf[0] = '%';

	i = len;
	if (!(p->f & LEFT_ALIGN))
	{
		while ((p->f & ZERO_FILL) && (len < p->width) && (len < BUF_SIZE))
			buf[len++] = '0';
	}
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