/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 11:58:13 by cjani             #+#    #+#             */
/*   Updated: 2020/08/02 11:58:19 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_len(int num)
{
	int				len;

	len = 1;
	while (num /= 10)
		len++;
	return (len);
}

static void			ft_putnum_abs(int n)
{
	long long int	num;
	char			c;

	num = (long long int)n;
	if (num < 0)
		num = -num;
	if (num >= 0 && num <= 9)
	{
		c = num + '0';
		ft_putchar(c);
	}
	if (num >= 10)
	{
		ft_putnum_abs(num / 10);
		ft_putnum_abs(num % 10);
	}
}

static int			put_digit(t_type *tab, int num, int len)
{
	if (len == 0)
		return (0);
	if (num < 0)
		ft_putchar('-');
	if (tab->flag == 2)
		ft_putzero(tab->width);
	ft_putzero(tab->height);
	ft_putnum_abs(num);
	return (1);
}

int					print_num(t_type *tab, va_list *arg)
{
	int				num;
	int				len;

	num = va_arg(*arg, int);
	len = get_len(num);
	if (tab->height == 0 && num == 0 && tab->is_height == 1)
		len = 0;
	if ((tab->height -= len) > 0)
		len += tab->height;
	if (num < 0)
		len += 1;
	if ((tab->width -= len) > 0)
	{
		if (tab->flag == 0)
			ft_putwhitespace(tab->width);
		put_digit(tab, num, len);
		if (tab->flag == 1)
			ft_putwhitespace(tab->width);
		return (tab->prtd += len + tab->width);
	}
	put_digit(tab, num, len);
	return (tab->prtd += len);
}
