/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 12:21:22 by cjani             #+#    #+#             */
/*   Updated: 2020/08/02 12:21:27 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(t_type *tab, va_list *arg)
{
	char	*str;
	size_t	len;

	str = va_arg(*arg, char *);
	if (!str)
		str = "(NULL)";
	len = ft_strlen(str);
	if (tab->height > (int)len || tab->height == 0)
		tab->height = (int)len;
	else if (tab->height != 0)
		len = tab->height;
	if ((tab->width) > (int)len)
	{
		tab->width -= len;
		if (tab->flag != 1)
			ft_putwhitespace(tab->width);
		write(1, str, tab->height);
		if (tab->flag == 1)
			ft_putwhitespace(tab->width);
		return (tab->i++);
	}
	write(1, str, tab->height);
	return (tab->i++);
}

int		print_char(t_type *tab, va_list *arg)
{
	char	c;

	c = va_arg(*arg, int);
	if (tab->width > 1)
	{
		tab->width -= 1;
		if (tab->flag != 1)
			ft_putwhitespace(tab->width);
		ft_putchar(c);
		if (tab->flag == 1)
			ft_putwhitespace(tab->width);
		return (tab->i++);
	}
	ft_putchar(c);
	return (tab->i++);
}