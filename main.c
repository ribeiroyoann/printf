/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:27:01 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/11 15:46:09 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(int argc, char **argv)
{
	int		nb = 12;
	ft_printf("[%.d %.0d]", 42, 43);
	printf("\n");
	printf("[%.d %.0d]", 42, 43);
	printf("\n\n");
	ft_printf("%#x", 0);
	printf("\n");
	printf("%#x", 0);
	printf("\n");
	ft_printf("size + hash + 0 + prec:%#05.3X", nb);
	printf("\n");
	ft_printf("size + hash + 0 + prec:%0#5.3X", nb);
	printf("\n");
	ft_printf("size + hash + minus + prec:%-#7.3X", nb);
	printf("\n-----------------\n");
	printf("size + hash + 0 + prec:%#05.3X", nb);
	printf("\n");
	printf("size + hash + 0 + prec:%0#5.3X", nb);
	printf("\n");
	printf("size + hash + minus + prec:%-#7.3X", nb);
	return (0);
}
