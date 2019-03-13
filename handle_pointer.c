/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:00:25 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/13 14:28:51 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pointer_len(intmax_t nb)
{
	int count;

	count = 0;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int		handle_pointer(t_parser *p, va_list args)
{
	intmax_t	pointer;
	char		*nb_str;
	char		buf[BUF_SIZE];
	int			len;
	int			ret;
	int			i;

	ret = 0;
	len = -1;
	pointer = va_arg(args, intmax_t);
	nb_str = itoa_base_long(p, pointer, 16, "0123456789abcdef");
	nb_str = ft_strjoin(nb_str, "x0");
	while (nb_str[++len])
		buf[len] = nb_str[len];
	i = len;
	if (!(p->f & LEFT_ALIGN) && !(p->f & ZERO_FILL))
		while (i++ < p->width && ++ret)
			ft_putchar(' ');
	i = -1;
	while (++i < len && ++ret)
		ft_putchar(buf[len - i - 1]);
	if (p->f & LEFT_ALIGN)
		while (i++ < p->width && ret++)
			ft_putchar(' ');
	return (ret);
}
