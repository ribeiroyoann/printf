/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:36:58 by yoann             #+#    #+#             */
/*   Updated: 2018/12/12 20:15:38 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_int_length(t_parser *p, va_list args)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	if (p->l == NONE)
		return ((int)nbr);
	else if (p->l == HH)
		return ((char)nbr);
	else if (p->l == H)
		return((short)nbr);
	else if (p->l == L)
		return ((long)nbr);
	else if (p->l == LL)
		return ((long long)nbr);
	printf("INT LENGTH ERROR\n");
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
