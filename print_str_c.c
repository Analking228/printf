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
	int		len;

	str = va_arg(*arg, char *);
	if (!str)
		str = "(NULL)";
	len = ft_strlen(str);
	if (tab->height > len || tab->height == 0)
		tab->height = len;
	else if (tab->height != 0)
		len = tab->height;
	if ((tab->width) > len)
	{
		tab->width -= len;
		tab->prtd += tab->width;
		if (tab->flag != 1)
			ft_putwhitespace(tab->width);
		write(1, str, tab->height);
		if (tab->flag == 1)
			ft_putwhitespace(tab->width);
		return (tab->i++);
	}
	write(1, str, tab->height);
	tab->prtd += len;
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
	tab->prtd += 1;
	return (tab->i++);
}