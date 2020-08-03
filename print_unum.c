/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 13:44:33 by cjani             #+#    #+#             */
/*   Updated: 2020/08/02 13:44:35 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned int unum)
{
	int		len;

	len = 1;
	while (unum /= 10)
		len++;
	return (len);
}

static void	put_unum(unsigned unum)
{
	char	c;

	if (unum >= 10)
		put_unum(unum / 10);
	c = (unum % 10) + '0';
	ft_putchar(c);
}

static void	put_main(t_type *tab, unsigned unum, int len)
{
	if (len == 0)
		return ;
	if (tab->flag == 2)
		ft_putzero(tab->width);
	ft_putzero(tab->height);
	put_unum(unum);
}
int			print_unum(t_type *tab, va_list *arg)
{
	unsigned int	unum;
	int				len;

	unum = va_arg(*arg, unsigned);
	len = get_len(unum);
	if (tab->height == 0 && unum == 0 && tab->is_height == 1)
		len = 0;
	if ((tab->height -= len) > 0)
		len += tab->height;
	if ((tab->width -= len) > 0)
	{
		if (tab->flag == 0)
			ft_putwhitespace(tab->width);
		put_main(tab, unum, len);
		if (tab->flag == 1)
			ft_putwhitespace(tab->width);
		return (tab->prtd += len + tab->width);
	}
	put_main(tab, unum, len);
	return (tab->prtd += len);
}