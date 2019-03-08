/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:27:01 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/08 19:28:19 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(int argc, char **argv)
{
	ft_printf("%hD", USHRT_MAX);
	printf("\n");
	printf("%hD", USHRT_MAX);

	return (0);
}
