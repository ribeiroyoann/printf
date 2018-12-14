/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:36:58 by yoann             #+#    #+#             */
/*   Updated: 2018/12/14 15:14:19 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_int_length(t_parser *p, va_list args)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	p->arg_len = ft_nb_len(nbr);
	if (p->f & NONE)
		return ((int)nbr);
	else if (p->f & HH)
		return ((char)nbr);
	else if (p->f & H)
		return((short)nbr);
	else if (p->f & L)
		return ((long)nbr);
	else if (p->f & LL)
		return ((long long)nbr);
	return (0);
}

// 18446744073709551615 == 20

// p->arg_len	== arg size
// p->len		== char to print
// p->pad		== fill

int			handle_int(t_parser *p, va_list args)
{
	intmax_t	nbr;
	char		*nb_str;
	char		ret[21];
	int			size;

	nbr = get_int_length(p, args);
	nb_str = ft_itoa(nbr);
	
}

