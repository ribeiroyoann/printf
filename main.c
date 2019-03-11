/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:27:01 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/11 13:47:59 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(int argc, char **argv)
{
	int		nb;
	nb = 45;
	ft_printf("size + hash + zero + prec:%#05.3o\n", nb);
	ft_printf("size + hash + zero + prec:%0#5.3o\n", nb);
	ft_printf("size + hash + minus + prec:%-#7.3o\n", nb);
	printf("\n");
	printf("-------------\n");
	printf("size + hash + zero + prec:%#05.3o\n", nb);
	printf("\n");
	printf("size + hash + zero + prec:%0#5.3o\n", nb);
	printf("\n");
	printf("size + hash + minus + prec:%-#7.3o\n", nb);
	printf("\n");

	return (0);
}
