/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:29:36 by yoann             #+#    #+#             */
/*   Updated: 2019/01/15 15:58:32 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_string(t_parser *p, va_list args)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (p->f & PRECISION)
		len = (len < p->precision ? len : p->precision);
	if (!(p->f & LEFT_ALIGN))
	{
		while (len < p->width)
		{
			ft_putchar(' ');
			i++;
			len++;
		}
	}
	while ((*str && (!(p->f & PRECISION) || p->precision--)))
	{
		ft_putchar(*str);
		str++;
		i++;
	}
	if (p->f & LEFT_ALIGN)
	{
		while (len < p->width)
		{
			ft_putchar(' ');
			len++;
			i++;
		}
	}
	return (i);
}
