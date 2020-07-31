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
	char	c;

	c = format[tab->i];
	if (c == '-' && tab->flag != 2) 
	{
		tab->flag = 1;
		return (1);
	}
	else if (c == '0' && tab->flag != 1)
	{
		tab->flag = 2;
		return (1);
	}
	return (0);
}

int			is_width(char *format, t_type *tab)
{
	char	str[13];
	int		i;

	if (((format[tab->i] >= '0') && (format[tab->i] <= '9')) || format[tab->i] == '*')
	{
		i = 0;
		while ((format[tab->i] >= '0') && (format[tab->i] <= '9'))
		{
			str[i] = format[tab->i];
			i++;
			tab->i++; 
		}
		if (str[0] && str[0] != '0')
			tab->width = ft_atoi(str);
		tab->i--;
		return (tab->width) ? 1 : 0;
	}
	return (0);
}

int			is_type(char *format, t_type *tab)
{
	char	c;

	c = format[tab->i];
	if (c == 'c')
		return (tab->ch = 1);
	else if (c == 's')
		return (tab->str = 1);
	else if (c == 'i' || c == 'd')
		return (tab->num = 1);
	else if (c == 'u')
		return (tab->unum = 1);
	else if (c == 'p')
		return (tab->pointer = 1);
	else if (c == 'x')
		return (tab->hex = 1);
	else if (c == 'X')
		return (tab->pointer = 2);
	return (0);
}
