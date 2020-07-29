/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:15:03 by cjani             #+#    #+#             */
/*   Updated: 2020/07/28 18:15:13 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		parse_guide()
{

}

int 		parser_types(t_type *tab, char *format)
{
	if (is_flag((char *)format, tab))
		return (1);
	if (is_width((char *)format, tab))
		return (1);
	return (0);
}

void		zerofication(t_type *tab)
{
	tab->minus = 0;
	tab->zero = 0;
	tab->width = 0;
	tab->height = 0;
	tab->num = 0;
	tab->ch = 0;
	tab->str = 0;
	tab->unum = 0;
	tab->pointer = 0;
	tab->hex = 0;
}

int			parser_main(const char *format)
{
	t_type	*tab;

	if (!(tab = (t_type *)malloc(sizeof(t_type *))))
		return (-1);
	tab->i = 0;
	while (format[tab->i] != 0)
	{
		if (format[tab->i] == '%' && format[tab->i + 1])
		{
			zerofication(tab);
			parser_types(tab, (char *)format);
		}
		else
			ft_putchar(format[tab->i]);
		tab->i++;
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list arg;
	
	va_start(arg, format);
	if (!parser_main(format))
		return (0);
	return (1);
}