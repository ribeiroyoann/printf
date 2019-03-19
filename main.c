/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:27:01 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/19 11:52:44 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#include <locale.h>
#include <wchar.h>

int		main(int argc, char **argv)
{
	int ret;


	setlocale(LC_ALL, "");
	ret = ft_printf("%lc, %lc", L'ÊM-^ZM-^V', L'ÿ≠');
	printf("\n%d\n", ret);
	printf("\n");
	ret = printf("%lc, %lc", L'ÊM-^ZM-^V', L'ÿ≠');
	printf("\n%d\n", ret);
 	return (0);
}

