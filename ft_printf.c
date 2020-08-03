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

static int	parser_err_check(const char *format, t_type *tab, va_list *arg)
{
	int		control;

	while (format[tab->i] != 0)
	{
		if (format[tab->i] == '%' && format[tab->i + 1] != '%')
		{
			tab->i++;
			zerofication(tab);
			control = parser_types(tab, (char *)format, arg);
			tab->i++;
			if (control < 0)
				return (-1);
		}
		else
		{
			if (format[tab->i] == '%')
				tab->i += 2;
			else
				tab->i++;
		}
	}
	return (1);
}

int			parser_types(t_type *tab, char *format, va_list *arg)
{
	while (is_flag((char *)format, tab) == 1)
		tab->i++;
	is_width((char *)format, tab, arg);
	if (format[tab->i] == '.')
	{
		tab->i++;
		if (!(is_type((char *)format, tab)))
		{
			if (!is_precision((char *)format, tab, arg))
				return (-1);
			else
			{
				if (tab->height < 0)
					tab->is_height = 0;
				else if (tab->flag == 2)
					tab->flag = 0;
			}
		}
		else
			tab->is_height = 1;
	}
	if (is_type((char *)format, tab))
		return (1);
	return (-1);
}

void		zerofication(t_type *tab)
{
	tab->flag = 0;
	tab->width = 0;
	tab->height = 0;
	tab->type = 0;
	tab->is_width = 0;
	tab->is_height = 0;
}

int			parser_main(const char *format, t_type *tab, va_list *arg)
{
	int		control;

	while (format[tab->i] != 0)
	{
		if (format[tab->i] == '%' && format[tab->i + 1] != '%')
		{
			tab->i++;
			zerofication(tab);
			control = parser_types(tab, (char *)format, arg);
			return (tab->i++) ? 2 : 0;
		}
		else
		{
			if (format[tab->i] == '%')
			{
				ft_putchar(format[tab->i]);
				tab->i += 2;
			}
			else
				ft_putchar(format[tab->i++]);
			tab->prtd++;
		}
		return (1);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list arg;
	int		control;
	t_type	tab;

	if (!format)
		return (-1);
	va_start(arg, format);
	tab.i = 0;
	tab.prtd = 0;
	if ((control = parser_err_check(format, &tab, &arg)) != -1)
	{
		va_end(arg);
		va_start(arg, format);
		tab.i = 0;
		while ((control = parser_main(format, &tab, &arg)) != 0)
			if (control == 2)
				print_with_type(&tab, &arg);
	}
	va_end(arg);
	return (control < 0) ? -1 : tab.prtd;
}
