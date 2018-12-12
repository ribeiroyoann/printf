/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:34:00 by yoann             #+#    #+#             */
/*   Updated: 2018/12/12 19:59:26 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_jumptable(t_jumptable handlers[128])
{
	handlers['d'] = &handle_int;
}

t_jumptable	init_table(char c)
{
	t_jumptable		handlers[128] = {NULL};

	if (!handlers['d'])
		set_jumptable(handlers);
	if (ft_isascii(c))
	{
		return (handlers[(int)c]);
	}
	else
		return (NULL);
}
