/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:10:29 by cjani             #+#    #+#             */
/*   Updated: 2020/07/29 12:11:46 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_type
{
	/*counter*/
	int				i;
    /*flags*/
	int				minus;
	int				zero;
    /*WidthNheight*/
	int				width;
	int				height;
    /*types*/
	int				num;
	unsigned int	unum;
	int				ch;
	int				str;
	unsigned int	hex;
	size_t			pointer;
}					t_type;

int					ft_printf(const char *, ...);
int					is_flag(char *format, t_type *tab);
int					is_width(char *format, t_type *tab);
int					print_with_type(t_type *tab, va_list *arg);
int					is_type(char *format, t_type *tab);
int     			parser_error_cheker(const char *format, t_type *tab);
void				zerofication(t_type *tab);
int 				parser_types(t_type *tab, char *format);

#endif
