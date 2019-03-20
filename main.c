/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:27:01 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/20 18:51:20 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#include <locale.h>
#include <wchar.h>

int		main(int argc, char **argv)
{
	int		nb;
	nb = 45;
	// ft_printf("test o:%o\n", nb);
	// ft_printf("hash:%#o\n", nb);
	// ft_printf("precision / grande:%.5o\n", nb);
	// ft_printf("precision / petite:%.0o\n", nb);
	// ft_printf("Prec + hash / grande:%#.5o\n", nb);
	// ft_printf("Prec + hash / petite:%#.1o\n", nb);
	// ft_printf("Prec + 0:%0.5o\n", nb);
	// ft_printf("Prec + minus:%-.5o\n", nb);
	// ft_printf("Size:%5o\n", nb);
	// ft_printf("size + prec:%7.3o\n", nb);
	// ft_printf("size + minus:%-5o\n", nb);
	// ft_printf("size + zero:%05o\n", nb);
	// ft_printf("size + zero + hash:%#05o\n", nb);
	// ft_printf("size + zero + prec:%05.3o\n", nb);
	// ft_printf("size + minus + prec:%-5.3o\n", nb);
	ft_printf("size + hash + zero + prec:%#05.3o\n", nb);
	// ft_printf("size + hash + zero + prec:%0#5.3o\n", nb);
	// ft_printf("size + hash + minus + prec:%-#7.3o\n", nb);
	printf("--------------------------------\n");
	// printf("test o:%o\n", nb);
	// printf("hash:%#o\n", nb);
	// printf("precision / grande:%.5o\n", nb);
	// printf("precision / petite:%.0o\n", nb);
	// printf("Prec + hash / grande:%#.5o\n", nb);
	// printf("Prec + hash / petite:%#.1o\n", nb);
	// printf("Prec + 0:%0.5o\n", nb);
	// printf("Prec + minus:%-.5o\n", nb);
	// printf("Size:%5o\n", nb);
	// printf("size + prec:%7.3o\n", nb);
	// printf("size + minus:%-5o\n", nb);
	// printf("size + zero:%05o\n", nb);
	// printf("size + zero + hash:%#05o\n", nb);
	// printf("size + zero + prec:%05.3o\n", nb);
	// printf("size + minus + prec:%-5.3o\n", nb);
	printf("size + hash + zero + prec:%#05.3o\n", nb);
	// printf("size + hash + zero + prec:%0#5.3o\n", nb);
	// printf("size + hash + minus + prec:%-#7.3o\n", nb);


}
