/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:51:20 by yoann             #+#    #+#             */
/*   Updated: 2019/03/14 15:56:55 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

long double		round_nbr(t_parser *p, long double nbr, int precision)
{
	long long	integer;
	long double	decimal;
	int			i;
	int			last;

	if (precision == 0)
	{
		integer = nbr * 10;
		return (nbr + (integer % 10 >= 5));
	}
	decimal = (nbr - (long long)nbr) * 10;
	i = 0;
	last = -1;
	while (precision-- > 0 && ++i)
	{
		if ((int)decimal == 9 || (int)decimal == -9)
			last = i;
		decimal = decimal - (long long)decimal;
		decimal *= 10;
	}
	decimal = last == -1 ? 0 : 0.1;
	decimal = nbr <= -0.0 ? -decimal : decimal;
	while (last-- > 0)
		decimal /= 10;
	return (nbr + decimal);
}

int		ft_uputnbr(long long n, int fd)
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

unsigned int	ft_abs(int value)
{
	if (value == INT_MIN)
		return ((unsigned int)INT_MAX + 1);
	return (value > 0 ? value : -value);
}

int			ft_print_float(t_parser *p, long double nbr, int fd)
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

int			handle_float(t_parser *p, va_list args)
{
	double	nbr;
	int		ret;

	if (p->f & FLAGS_L)
		nbr = va_arg(args, long double);
	else
		nbr = va_arg(args, double);
	if (!(p->f & PRECISION))
		p->precision = 6;
	nbr = round_nbr(p, nbr, p->precision);
	ret = ft_print_float(p, nbr, 2);
	return (ret);
}

