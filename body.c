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
			if (control < 0 || !(check_arg_status((char *)format, tab, arg)))
                return (-1);
		}
        else
            tab->i++;
	}
	return (1);
}

int 	check_arg_status(char *format, t_type *tab, va_list *arg)
{
	if (tab->ch)
		return (va_arg(*arg, int)) ? 1 : 0;
	if (tab->str)
		return (va_arg(*arg, char *)) ? 1 : 0;
	if (tab->num)
		return (va_arg(*arg, int)) ? 1 : 0;
	if (tab->unum)
		return (va_arg(*arg, unsigned int)) ? 1 : 0;
	if (tab->pointer)
		return (va_arg(*arg, size_t)) ? 1 : 0;
	if (tab->hex)
		return (va_arg(*arg, unsigned int)) ? 1 : 0;
	return (1);
}