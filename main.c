/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:27:01 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/15 19:26:19 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#include <locale.h>
#include <wchar.h>

int		main(int argc, char **argv)
{
	ft_printf("%#.o", '\\xff');
	printf("\n");
	printf("%#.o", '\\xff');
	printf("\n");
	ft_printf("%#.o", 0);
	printf("\n");
	printf("%#.o", 0);
	printf("\n-----------\n");
	ft_printf("%.o %.0o", 0, 0);
	printf("\n");
	printf("%.o %.0o", 0, 0);
 	return (0);
}
