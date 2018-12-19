/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:44:15 by yoann             #+#    #+#             */
/*   Updated: 2018/12/19 16:52:02 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_octal(t_parser *p, va_list args)
{
	intmax_t	nbr;

	nbr = get_int_length(p, args);
	return (nbr);
}