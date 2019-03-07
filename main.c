/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:27:01 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/07 14:45:36 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	printf("%.o %.0o", 0, 0);
	printf("\n--------\n");
	ft_printf("%.o %.0o", 0, 0);
	printf("\n--------\n");
	printf("%5.o %5.0o", 0, 0);
	printf("\n--------\n");
	ft_printf("%5.o %5.0o", 0, 0);
	printf("\n--------\n");
	printf("%#.o %#.0o", 0, 0);
	printf("\n");
	ft_printf("%#.o %#.0o", 0, 0);
	printf("\n\n");
	printf("[%#.x %#.0x]", 0, 0);
	printf("\n");
	ft_printf("[%#.x %#.0x]", 0, 0);

	return (0);
}