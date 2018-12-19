/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:47:12 by yoann             #+#    #+#             */
/*   Updated: 2018/12/19 18:45:21 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	printBits(sizeof(p->f), &p->f);
}

void    printBits(size_t const size, void const * const ptr)
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

unsigned int        nb_len1(int n)
{
    unsigned int    count;

    count = 1;
    while (n /= 10)
        count++;
    return (count);
}

char                *ft_itoa1(t_parser *p, int n)
{
    unsigned int    count;
    unsigned int    nb;
    unsigned int    i;
    char            *str;

    count = nb_len1(n);
    nb = n;
    if (n < 0)
    {
        p->f |= NEG;
        nb = -n;
    }
    if (!(str = ft_strnew(count)))
        return (0);
    if (!nb)
        str[0] = '0';
    str[count] = '\0';
    i = 0;
    while (nb)
    {
        str[i++] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}

char                *itoa_base(t_parser *p, int n, int base)
{
    unsigned int    count;
    unsigned int    nb;
    unsigned int    i;
    char            *str;
    char            *s_base = "0123456789ABCDEF";

    count = nb_len1(n);
    nb = n;
    if (n < 0)
    {
        p->f |= NEG;
        nb = -n;
    }
    if (!(str = ft_strnew(count)))
        return (0);
    if (!nb)
        str[0] = '0';
    str[count] = '\0';
    i = 0;
    while (nb)
    {
        str[i++] = s_base[nb % base];
        nb /= base;
    }
    return (str);
}

int     get_base(t_parser *p, char c)
{
    if (c == 'd' || c == 'i')
        return (10);
    else if (c == 'o')
        return (8);
    else if (c == 'x' || c == 'X')
        return (16);
    else return (-1);
}