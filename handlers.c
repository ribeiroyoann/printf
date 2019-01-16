/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:34:00 by yoann             #+#    #+#             */
/*   Updated: 2019/01/16 15:07:16 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_jumptable(t_jumptable handlers[128])
{
	handlers['d'] = &handle_int;
	handlers['i'] = &handle_int;
	handlers['o'] = &handle_int;
	handlers['u'] = &handle_int;
	handlers['x'] = &handle_int;
	handlers['X'] = &handle_int;
	handlers['s'] = &handle_string;
	handlers['c'] = &handle_char;
	handlers['p'] = &handle_pointer;
	handlers['%'] = &handle_escape;
}

t_jumptable	init_table(char c)
{
	t_jumptable		handlers[128] = {NULL};

	if (!handlers['d'])
		set_jumptable(handlers);
	if (ft_isascii(c))
		return (handlers[(int)c]);
	else
		return (NULL);
}