/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:08:25 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/20 15:49:35 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_base_long(t_parser *p, long long int n, int base, char *s_base)
{
	uintmax_t		nb;
	unsigned int	i;
	char			*str;

	nb = n;
	p->slen = ft_nblen(n);
	if (n < 0)
		nb = -n;
	if (!(str = ft_strnew(p->slen)))
		return (0);
	if (!nb)
	{
		p->f |= ZEROVALUE;
		str[0] = '0';
	}
	str[p->slen] = '\0';
	i = 0;
	while (nb)
	{
		str[i++] = s_base[nb % base];
		nb /= base;
	}
	return (str);
}

char	*itoa_base_ulong(t_parser *p, uintmax_t n, int base, char *s_base)
{
	uintmax_t			nb;
	unsigned int		i;
	char				*str;

	nb = n;
	p->slen = ft_nblen(n);
	if (!(str = ft_strnew(p->slen)))
		return (0);
	if (!nb)
	{
		p->f |= ZEROVALUE;
		str[0] = '0';
	}
	str[p->slen + 1] = '\0';
	i = 0;
	while (nb)
	{
		str[i] = s_base[nb % base];
		nb /= base;
		i++;
	}
	return (str);
}

void	print_buffer(char *buf, int len, int *ret)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putchar(buf[len - i - 1]);
		i++;
		(*ret)++;
	}
}

int		get_base(t_parser *p, char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
	{
		if (c == 'u')
			p->f |= UNSIGNED;
		return (10);
	}
	else if (c == 'o')
		return (8);
	else if (c == 'x' || c == 'X')
	{
		if (c == 'X')
			p->f |= CAPSBASE;
		return (16);
	}
	else
		return (-1);
}

size_t	ft_wstrlen(const int *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
