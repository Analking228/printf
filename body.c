/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:15:03 by cjani             #+#    #+#             */
/*   Updated: 2020/07/28 18:15:13 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     print_with_type(t_type *tab, va_list *arg)
{
	if (tab->ch)
		return (print_char(tab, arg));
	else if (tab->str)
		return (print_str(tab, arg));
	else if (tab->num)
		return (print_num(tab, arg));
	else if (tab->unum)
		return (print_unum(tab, arg));
	else if (tab->pointer)
		return (print_pointer(tab, arg));
	else if (tab->hex)
		return (print_hex(tab, arg));
    return(1);
}

int     parser_error_cheker(const char *format, t_type *tab, va_list *arg)
{
    int		control;

	while (format[tab->i] != 0)
	{
		if (format[tab->i] == '%' && format[tab->i++ + 1] != '%')
		{
			zerofication(tab);
			while (!(control = parser_types(tab, (char *)format, arg)))
				tab->i++;
			tab->i++;
			if (control < 0)
			{
				write(1, &format[tab->i], 1);
                return (-1);
			}
		}
        else
            tab->i++;
	}
	return (1);
}
