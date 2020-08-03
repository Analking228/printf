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

static int	get_len(size_t ptr)
{
	int		len;

	len = 1;
	while (ptr /= 16)
		len++;
	return (len);
}

static void	put_main(size_t ptr)
{
	char	*arr;

	arr = "0123456789abcdef";
	if (ptr >= 16)
		put_main(ptr / 16);
	ft_putchar(arr[ptr % 16]);
}

static void	put_ptr(t_type *tab, size_t ptr, int len)
{
	ft_putstr("0x");
	if (len == 0)
		return ;
	if (tab->flag == 0)
		ft_putzero(tab->width);
	ft_putzero(tab->height);
	put_main(ptr);
}

int			print_pointer(t_type *tab, va_list *arg)
{
	size_t	ptr;
	int		len;

	ptr = va_arg(*arg, size_t);
	len = get_len(ptr);
	if (tab->height == 0 && ptr == 0 && tab->is_height == 1)
		len = 0;
	if ((tab->height -= len) > 0)
		len += tab->height;
	if ((tab->width -= (len + 2)) > 0)
	{
		if (tab->flag == 0)
			ft_putwhitespace(tab->width);
		put_ptr(tab, ptr, len);
		if (tab->flag == 1)
			ft_putwhitespace(tab->width);
		return (tab->prtd += len + tab->width + 2);
	}
	put_ptr(tab, ptr, len);
	return (tab->prtd += len + 2);
}
