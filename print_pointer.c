/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 12:56:57 by cjani             #+#    #+#             */
/*   Updated: 2020/08/02 12:57:00 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(size_t arg)
{
	int		len;

	len = 1;
	while (arg /= 16)
		len += 1;
	return (len);
}

static void	put_main(size_t arg)
{
	char	*arr;

	arr = "0123456789abcdef";
	if (arg >= 16)
		put_main(arg / 16);
	ft_putchar(arr[arg % 16]);
}

static void	put_ptr(t_type *tab, size_t arg, int len)
{
	ft_putstr("0x");
	if (len == 0)
		return ;
	if (tab->flag == 0)
		ft_putzero(tab->width);
	ft_putzero(tab->height);
	put_main(arg);
}

int			print_pointer(t_type *tab, va_list *arg)
{
	size_t	ptr;
	int		len;

	ptr = va_arg(*arg, size_t);
	len = get_len(ptr);
	if (tab->height == 0 && ptr == 0)
		len = 0;
	if ((tab->height -= len) > 0)
		len += tab->height;
	if ((tab->width -= (len + 2)) > 0)
	{
		tab->prtd += len + tab->width + 2;
		if (tab->flag == 0)
			ft_putwhitespace(tab->width);
		put_ptr(tab, ptr, len);
		if (tab->flag == 1)
			ft_putwhitespace(tab->width);
		return (tab->i++);
	}
	tab->prtd += len + 2;
	put_ptr(tab, ptr, len);
	return (tab->i++);
}
