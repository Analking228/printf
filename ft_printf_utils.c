/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:54:01 by cjani             #+#    #+#             */
/*   Updated: 2020/07/29 15:54:30 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_flag(char *format, t_type *tab)
{
	if (format[tab->i] == '-') 
	{
		tab->flag = 1;
		return (1);
	}
	else if (format[tab->i] == '0' && tab->flag != 1)
	{
		tab->flag = 2;
		return (1);
	}
	return (0);
}

int			is_width(char *format, t_type *tab, va_list *arg)
{

	int		i;

	if (format[tab->i] == '*')
	{
		tab->width = va_arg(*arg, int);
		if (tab->width < 0)
		{
			tab->width = -tab->width;
			tab->flag = 1;
		}
		tab->is_width = 1;
		tab->i++;
	}
	else if (ft_isdigit(format[tab->i]))
	{
		tab->width = ft_atoi(&format[tab->i]);
		while (ft_isdigit(format[tab->i]) && format[tab->i])
			tab->i++;
		tab->is_width = 1;
	}
	return (tab->is_width) ? 1 : 0;
}

int			is_precision(char *format, t_type *tab, va_list *arg)
{
	if (format[tab->i] == '*')
	{
		tab->height = va_arg(*arg, int);
		tab->i++;
		tab->is_height = 1;
	}
	else if (format[tab->i] == '-' || ft_isdigit(format[tab->i]))
	{
		tab->height = ft_atoi(&format[tab->i]);
		if (format[tab->i] == '-')
			tab->i++;
		while (ft_isdigit(format[tab->i]) && format[tab->i])
		{
			tab->i++;
			tab->is_height = 1;
		}
		if (tab->height >= 0 && tab->flag == 1 && !tab->is_width)
			tab->flag = 2;
	}
	return (tab->is_height) ? 1 : 0;
}

int			is_type(char *format, t_type *tab)
{
	char	c;

	c = format[tab->i];
	if (c == 'c')
		return (tab->type = 'c');
	else if (c == 's')
		return (tab->type = 's');
	else if (c == 'i' || c == 'd')
		return (tab->type = 'd');
	else if (c == 'u')
		return (tab->type = 'u');
	else if (c == 'p')
		return (tab->type = 'p');
	else if (c == 'x')
		return (tab->type = 'x');
	else if (c == 'X')
		return (tab->type = 'X');
	return (0);
}

void	ft_putwhitespace(int i)
{
	while (i-- > 0)
		ft_putchar(' ');
}

void	ft_putzero(int i)
{
	while (i-- > 0)
		ft_putchar('0');
}