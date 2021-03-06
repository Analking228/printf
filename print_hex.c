/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:49:21 by cjani             #+#    #+#             */
/*   Updated: 2020/08/03 16:49:24 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned int i)
{
	int		len;

	len = 1;
	while (i /= 16)
		len++;
	return (len);
}

static void	put_hex(unsigned hex, t_type *tab)
{
	char	*arr;

	if (tab->type == 'x')
		arr = "0123456789abcdef";
	else
		arr = "0123456789ABCDEF";
	if (hex >= 16)
		put_hex(hex / 16, tab);
	ft_putchar(arr[hex % 16]);
}

static void	put_main(t_type *tab, unsigned hex, int len)
{
	if (len == 0)
		return ;
	if (tab->flag == 2)
		ft_putzero(tab->width);
	ft_putzero(tab->height);
	put_hex(hex, tab);
}

int			print_hex(t_type *tab, va_list *arg)
{
	unsigned int	hex;
	int				len;

	hex = va_arg(*arg, unsigned);
	len = get_len(hex);
	if (tab->height == 0 && hex == 0 && tab->is_height == 1)
		len = 0;
	if ((tab->height -= len) > 0)
		len += tab->height;
	if ((tab->width -= len) > 0)
	{
		if (tab->flag == 0)
			ft_putwhitespace(tab->width);
		put_main(tab, hex, len);
		if (tab->flag == 1)
			ft_putwhitespace(tab->width);
		return (tab->prtd += len + tab->width);
	}
	put_main(tab, hex, len);
	return (tab->prtd += len);
}
