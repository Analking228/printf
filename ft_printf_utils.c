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
	if (c == '-')
	{
		tab->minus = 1;
		return (1);
	}
	else if (c == '0')
	{
		tab->zero = 1;
		return (1);
	}
	return (0);
}

int			is_width(char *format, t_type *tab)
{
	char	str[13];
	int		i;

	if (((format[tab->i] > '0') && (format[tab->i] < '9')) || format[tab->i] == '*')
	{
		i = 0;
		while ((format[tab->i] > '0') && (format[tab->i] < '9'))
		{
			str[i] = format[tab->i];
			i++;
			tab->i++; 
		}
		if (str[0])
			tab->width = ft_atoi(str);
		else
			tab->width = -1;
		return (1);
	}
	return (0);
}
