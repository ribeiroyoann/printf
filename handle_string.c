/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:29:36 by yoann             #+#    #+#             */
/*   Updated: 2019/01/11 15:21:16 by yoann            ###   ########.fr       */
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
	len = ft_strlen(str);
	if (p->f & PRECISION)
		len = (len < p->precision ? len : p->precision);
	// printf("LEN %d WIDTH %d PREC %d\n", len, p->width, p->precision);
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
