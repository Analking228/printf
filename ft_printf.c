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

int 		parser_types(t_type *tab, char *format, va_list *arg)
{
	if (is_flag((char *)format, tab))
	{
		write(1, "f", 1);
		return (0);
	}
	else if (is_width((char *)format, tab, arg))
	{
		write(1, "w", 1);
		return (0);
	}
	else if (is_type((char *)format, tab))
	{
		write(1, "t", 1);
		return (1);
	}
	else if (is_precision((char *)format, tab, arg))
	{
		write(1, "p", 1);
		return (1);
	}
	else
		return (-1);
}

void		zerofication(t_type *tab)
{
	tab->flag = 0;
	tab->width = 0;
	tab->height = 0;
	tab->num = 0;
	tab->ch = 0;
	tab->str = 0;
	tab->unum = 0;
	tab->pointer = 0;
	tab->hex = 0;
}

int			parser_main(const char *format, t_type *tab, va_list *arg)
{
	int		control;

	while (format[tab->i] != 0)
	{
		if (format[tab->i] == '%' && format[tab->i++ + 1] != '%')
		{
			zerofication(tab);
			while (!(control = parser_types(tab, (char *)format, arg)))
				tab->i++;
		}
		else
			ft_putchar(format[tab->i]);
		tab->i++;
		return (1);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list arg;
	int		control;
	t_type	tab;

	va_start(arg, format);
	tab.i = 0;
	if ((control = parser_error_cheker(format, &tab, &arg)) < 0)
		write(1, "Wrong printf input", 18);
	else
	{
		va_end(arg);
		va_start(arg, format);
		tab.i = 0;
		while ((control = parser_main(format, &tab, &arg)) != 0)
			if (control == 2)
				print_with_type(&tab, &arg);
	}
	va_end(arg);
	return (control < 0) ? -1 : 1;
}