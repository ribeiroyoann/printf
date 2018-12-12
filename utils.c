/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:47:12 by yoann             #+#    #+#             */
/*   Updated: 2018/12/12 17:04:33 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	init_parser(t_parser *p)
// {

// }

char	*ft_strpbrk(const char *s1, const char *s2)
{
    while (*s1)
        if (ft_strchr(s2, *s1++))
            return (char*)--s1;
    return (0);
}

void	print_parser(t_parser *p)
{
	printf("\n");
	printf("\n");
	printf("p->space        %d\n", p->space);
	printf("p->left_justify %d\n", p->left_justify);
	printf("p->plus		%d\n", p->plus);
	printf("p->zero_padded  %d\n", p->zero_padded);
	printf("p->prefix       %d\n", p->prefix);
	printf("p->width        %d\n", p->width);
	printf("p->precision    %d\n", p->precision);
	printBits(sizeof(p->l), &p->l);
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}