#include "ft_printf.h"

int			print_char(t_type *tab, va_list *arg)
{
	char	c;

	c = va_arg(*arg, int);
	ft_putchar(c);
	tab->i++;
	return (1);
}

int			print_str(t_type *tab, va_list *arg)
{
	char	*str;

	str = va_arg(*arg, char *);
	ft_putstr(str);
	tab->i++;
	return (1);
}

int			print_num(t_type *tab, va_list *arg)
{
	int		num;
	char	*str;

	num = va_arg(*arg, int);
	str = ft_itoa(num);
	ft_putstr(str);
	free(str);
	tab->i++;
	return (1);
}

int			print_unum(t_type *tab, va_list *arg)
{
	return (1);
}

int			print_pointer(t_type *tab, va_list *arg)
{
	return (1);
}

int			print_hex(t_type *tab, va_list *arg)
{
	return (1);
}