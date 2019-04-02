/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:51:20 by yoann             #+#    #+#             */
/*   Updated: 2019/04/02 19:19:44 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int				calc_decimal(long double decimal, int precision, int pos)
{
	int	i;

	i = 0;
	while (precision-- > 0 && ++i)
	{
		if ((int)decimal == 9 || (int)decimal == -9)
			pos = i;
		decimal = decimal - (long long)decimal;
		decimal *= 10;
	}
	return (pos);
}

long double		round_nbr(long double nbr, int precision)
{
	long long	integer;
	long double	decimal;
	int			pos;

	if (precision == 0)
	{
		integer = nbr * 10;
		return (nbr + (integer % 10 >= 5));
	}
	decimal = (nbr - (long long)nbr) * 10;
	pos = -1;
	pos = calc_decimal(decimal, precision, pos);
	if (pos == -1)
		decimal = 0;
	else
		decimal = 0.1;
	if (nbr <= -0.0)
		decimal = -decimal;
	while (pos-- > 0)
		decimal /= 10;
	return (nbr + decimal);
}

int				ft_uputnbr(long long n, int fd)
{
	int i;

	i = 1;
	if (n < 0)
		n = -n;
	if (n >= 10)
		i += ft_uputnbr(n / 10, fd);
	ft_putchar('0' + n % 10);
	return (i);
}

int				ft_print_float(t_parser *p, long double nbr, int fd)
{
	long long	n;
	int			i;

	i = 0;
	n = (long long)nbr;
	if (nbr < 0 && ++i)
		ft_putchar('-');
	i += ft_uputnbr(n, fd);
	if (!p->precision)
		return (i);
	i += p->precision + 1;
	ft_putchar('.');
	nbr -= (long long)nbr;
	while (p->precision-- > 0)
	{
		nbr *= 10;
		n = (long long)nbr % 10;
		nbr -= (long long)nbr;
		ft_putchar('0' + ft_abs(n));
	}
	return (i);
}

int				handle_float(t_parser *p, va_list args)
{
	long double	nbr;
	int			ret;

	if (p->f & FLAGS_L)
		nbr = va_arg(args, long double);
	else
		nbr = va_arg(args, double);
	if (!(p->f & PRECISION))
		p->precision = 6;
	nbr = round_nbr(nbr, p->precision);
	ret = ft_print_float(p, nbr, 2);
	return (ret);
}
