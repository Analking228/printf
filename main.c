/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:47:08 by cjani             #+#    #+#             */
/*   Updated: 2020/07/29 12:48:03 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int     main()
{
    int     test;
    char    *str = "qwerty";

    test = 5;
    ft_printf("lolkek %6.6s\n %c", 15, 15);
    printf("afafa %05dggggg", -3);
    return (1);
}

