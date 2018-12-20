/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:00:25 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/20 17:50:20 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(int nb)
{
	char	str[] = "0123456789abcdef";

	if (nb >= 16)
		print_hexa(nb / 16);
	ft_putchar(str[nb % 16]);
}

int		handle_pointer(t_parser *p, va_list args)
{
	intmax_t	pointer;

	pointer = va_arg(args, intmax_t);
	ft_putstr("0x7fff");
	print_hexa(pointer);
	return (1);
}