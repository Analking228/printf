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
    unsigned int     test;
    char    *str = "qwerty";

    test = 1234567899;
    ft_printf("\nlolkek %u", test);
    printf("\nlolkek %u", test);
    return (1);
}

