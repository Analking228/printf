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
	if (tab->type == 'c')
		return (print_char(tab, arg));
	else if (tab->type == 's')
		return (print_str(tab, arg));
	else if (tab->type == 'd')
		return (print_num(tab, arg));
	else if (tab->type == 'u')
		return (print_unum(tab, arg));
	else if (tab->type == 'p')
		return (print_pointer(tab, arg));
	else if (tab->type == 'x' || tab->type == 'X')
		return (print_hex(tab, arg));
    return(1);
}
