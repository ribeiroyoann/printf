/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:27:01 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/21 13:40:23 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#include <locale.h>
#include <wchar.h>

int		main(int argc, char **argv)
{
	int		nb;
	nb = 0;
	// ft_printf("big prec : %+.420d\n", nb);
	// nb = 12354;
	// ft_printf("big prec : %+.250d\n", nb);

	// nb = 0;
	// dprintf(2, "big prec : %+.420d\n", nb);
	// nb = 12354;
	// dprintf(2, "big prec : %+.250d\n", nb);

	nb = -45;
	ft_printf("space% d\n", nb);
	ft_printf("plus:%+d\n", nb);
	ft_printf("precision:%.5d\n", nb);
	ft_printf("space + prec:% .5d\n", nb);
	ft_printf("Plus + prec / grande:%+.5d\n", nb);
	ft_printf("Plus + prec / petite:%+.0d\n", nb);
	ft_printf("Prec + 0:%0.5d\n", nb);
	ft_printf("Prec + minus:%-.5d\n", nb);
	ft_printf("size:%5d\n", nb);
	ft_printf("size + space:% 5d\n", nb);
	ft_printf("size + plus:%+5d\n", nb);
	ft_printf("size + minus:%-5d\n", nb);
	ft_printf("size + 0:%05d\n", nb);
	ft_printf("size + 0 + plus:%+05d\n", nb);
	ft_printf("size + 0 + plus:%0+5d\n", nb);
	ft_printf("size + 0 + prec:%05.3d\n", nb);
	ft_printf("size + minus + prec:%-5.3d\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3d\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3d\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3d\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3d\n", nb);

	dprintf(2, "space% d\n", nb);
	dprintf(2, "plus:%+d\n", nb);
	dprintf(2, "precision:%.5d\n", nb);
	dprintf(2, "space + prec:% .5d\n", nb);
	dprintf(2, "Plus + prec / grande:%+.5d\n", nb);
	dprintf(2, "Plus + prec / petite:%+.0d\n", nb);
	dprintf(2, "Prec + 0:%0.5d\n", nb);
	dprintf(2, "Prec + minus:%-.5d\n", nb);
	dprintf(2, "size:%5d\n", nb);
	dprintf(2, "size + space:% 5d\n", nb);
	dprintf(2, "size + plus:%+5d\n", nb);
	dprintf(2, "size + minus:%-5d\n", nb);
	dprintf(2, "size + 0:%05d\n", nb);
	dprintf(2, "size + 0 + plus:%+05d\n", nb);
	dprintf(2, "size + 0 + plus:%0+5d\n", nb);
	dprintf(2, "size + 0 + prec:%05.3d\n", nb);
	dprintf(2, "size + minus + prec:%-5.3d\n", nb);
	dprintf(2, "size + plus + 0 + prec:%+05.3d\n", nb);
	dprintf(2, "size + espace + zero + prec:%0 5.3d\n", nb);
	dprintf(2, "size + espace + zero + prec:% 05.3d\n", nb);
	dprintf(2, "size + minus + plus + prec:%-+5.3d\n", nb);
}
