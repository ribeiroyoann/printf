/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:27:01 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/20 14:32:44 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#include <locale.h>
#include <wchar.h>

int		main(int argc, char **argv)
{
	int ret;

	wchar_t *str = NULL;
	setlocale(LC_ALL, "");
	ret = ft_printf("%S", str);
	printf("\nret%d\n", ret);
	printf("\n");
	ret = printf("%.d %.0d", 0, 0);
	printf("\nret%d\n", ret);
 	return (0);
}
