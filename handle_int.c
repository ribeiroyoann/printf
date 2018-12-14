/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:36:58 by yoann             #+#    #+#             */
/*   Updated: 2018/12/14 18:53:03 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_int_length(t_parser *p, va_list args)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	p->arg_len = ft_nb_len(nbr);
	if (p->f & NONE)
		return ((int)nbr);
	else if (p->f & HH)
		return ((char)nbr);
	else if (p->f & H)
		return((short)nbr);
	else if (p->f & L)
		return ((long)nbr);
	else if (p->f & LL)
		return ((long long)nbr);
	return (0);
}

// 18446744073709551615 == 20

// p->arg_len	== arg size
// p->len		== char to print
// p->pad		== fill

#define BUF_SIZE 21

int			handle_int(t_parser *p, va_list args)
{
	intmax_t	nbr;
	char		*nb_str;
	char		buf[BUF_SIZE];
	int			len;
	int			idx;
	int			start_idx;

	idx = 0;
	start_idx = idx;
	len = -1;
	nbr = get_int_length(p, args);
	nb_str = ft_itoa(nbr);

	while (nb_str[++len])
		buf[len] = nb_str[len];
	printf("[%s]\n", buf);
	// ZERO FILL && !LEFT_ALIGN
	if (!(p->f & LEFT_ALIGN))
	{
		while ((p->f & ZERO_FILL) && (len < p->width) && (len < BUFF_SIZE))
			buf[len++] = '0';
	}


	int i = len;
	if (!(p->f & LEFT_ALIGN) && !(p->f & ZERO_FILL))
	{

			while (i < p->width)
			{
				ft_putchar(' ');
				i++;
				idx++;
			}
	}

  	i = 0;
  	while (i < len)
  	{
  		ft_putchar(buf[len - i - 1]);
  		i++;
  		idx++;
  	}

  	if (p->f & LEFT_ALIGN)
  	{
  		while (idx - start_idx < p->width)
  		{
  			ft_putchar(' ');
  			idx++;
  		}
  	}

	// ft_putstr(buf);
	return (idx);
}


