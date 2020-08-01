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
		/*write(1, "\n", 1);
		write(1, &format[tab->i], 1);*/
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
