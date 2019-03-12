/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:51:20 by yoann             #+#    #+#             */
/*   Updated: 2019/03/12 18:44:39 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

long double		round_nbr(t_parser *p, long double nbr)
{
	long long	tmp;
	long double	tmp2;
	int			idx;
	int			last;

	if (p->precision == 0)
	{
		tmp = nbr * 10;
		return (nbr + (tmp % 10 >= 5));
	}
	tmp2 = (nbr - (long long)nbr) * 10;
	idx = 0;
	last = -1;
	while (p->precision-- > 0 && ++idx)
	{
		if ((int)tmp2 == 9 || (int)tmp2 == -9)
			last = idx;
		tmp2 = tmp2 - (long long)tmp2;
		tmp2 *= 10;
	}
	tmp2 = last == -1 ? 0 : 0.1;
	tmp2 = nbr <= -0.0 ? -tmp2 : tmp2;
	while (last-- > 0)
		tmp2 /= 10;
	return (nbr + tmp2);
}

int		ft_putllnbr(long long n, int fd)
{
	int i;

	i = 1;
	if (n < 0)
		n = -n;
	if (n >= 10)
		i += ft_putllnbr(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
	return (i);
}

unsigned int	ft_abs(int value)
{
	if (value == INT_MIN)
		return ((unsigned int)INT_MAX + 1);
	return (value > 0 ? value : -value);
}

int			ft_print_float(long double nbr, int precision, int fd)
{
	long long	n;
	int			i;

	i = 0;
	n = (long long)nbr;
	if (nbr < 0 && ++i)
		ft_putchar_fd('-', fd);
	i += ft_putllnbr(n, fd);
	if (precision == 0)
		return (i);
	i += precision + 1;
	ft_putchar_fd('.', fd);
	nbr -= (long long)nbr;
	while (precision-- != 0)
	{
		nbr *= 10;
		n = (long long)nbr % 10;
		nbr -= (long long)nbr;
		ft_putchar_fd('0' + ft_abs(n), fd);
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
	printf("va arg [%f]\n", nbr);
	nbr = round_nbr(p, nbr);
	printf("round = %f\n", nbr);
	ret = ft_print_float(nbr, p->precision, 2);
	return (ret);
}

