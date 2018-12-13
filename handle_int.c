/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:36:58 by yoann             #+#    #+#             */
/*   Updated: 2018/12/13 11:52:33 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_int_length(t_parser *p, va_list args)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	if (p->f == NONE)
		return ((int)nbr);
	else if (p->f == HH)
		return ((char)nbr);
	else if (p->f == H)
		return((short)nbr);
	else if (p->f == L)
		return ((long)nbr);
	else if (p->f == LL)
		return ((long long)nbr);
	return (0);
}

int			handle_int(t_parser *p, va_list args)
{
	intmax_t	nbr;
	char		*ret;

	nbr = get_int_length(p, args);
	ret = ft_itoa(nbr);
	ft_putstr(ret);
	return (ft_strlen(ret));
}
