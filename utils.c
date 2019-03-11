/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:08:25 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/11 13:15:10 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strpbrk(const char *s1, const char *s2)
{
	printf("%s\n", s1);
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

unsigned int        nb_len1(unsigned long long n)
{
	unsigned int    count;

	count = 1;
	while (n /= 10)
		count++;
	return (count);
}

char				*itoa_base_long(t_parser *p, long long int n, int base, char *s_base)
{
	uintmax_t       nb;
	unsigned int    i;
	char            *str;

	nb = n;
	if (n < 0)
	{
		p->f |= NEG;
		nb = -n;
	}
	if (!(str = ft_strnew(nb_len1(n))))
		return (0);
	if (!nb)
	{
		p->f |= ZEROVALUE;
		str[0] = '0';
	}
	str[nb_len1(n)] = '\0';
	i = 0;
	if (p->f & ZEROVALUE && ((p->f & PRECISION) && !p->precision) && (!(p->f & PREFIX) || p->format == 'x'))
		return ("");
	while (nb)
	{
		str[i++] = s_base[nb % base];
		nb /= base;
	}
	return (str);
}

char				*itoa_base_ulong(t_parser *p, unsigned long long n, int base, char *s_base)
{
	unsigned long long       nb;
	unsigned int    i;
	char            *str;

	nb = n;
	if (!(str = ft_strnew(nb_len1(n))))
		return (0);
	if (!nb)
	{
		p->f |= ZEROVALUE;
		str[0] = '0';
	}
	str[nb_len1(n)] = '\0';
	i = 0;
	if (p->f & ZEROVALUE && ((p->f & PRECISION) && !p->precision) && (!(p->f & PREFIX) || p->format == 'x'))
		return ("");
	while (nb)
	{
		str[i++] = s_base[nb % base];
		nb /= base;
	}
	return (str);
}

int     get_base(t_parser *p, char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
	{
		if (c == 'u')
			p->f |= UNSIGNED;
		return (10);
	}
	else if (c == 'o')
		return (8);
	else if (c == 'x' || c == 'X')
	{
		if (c == 'X')
			p->f |= CAPSBASE;
		return (16);
	}
	else return (-1);
}

char    *toUpper(char *str) {
  size_t len = ft_strlen(str);
  size_t i;

  for (i = 0; i < len; i++) {
	if (str[i] >= 'a' && str[i] <= 'z') {
	  str[i] = str[i] - 'a' + 'A';
	}
  }
  return str;
}

char    *ft_strrev(char *str)
{
	int     i;
	int     length;
	char    buff;

	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
		i++;
	}
	return (str);
}