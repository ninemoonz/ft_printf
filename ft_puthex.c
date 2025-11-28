/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:59:22 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/28 15:25:36 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(unsigned int n)
{
    char *hex_letter = "0123456789abcdef";
    int hex_nbr;

    hex_nbr = 0;
    if (n >= 16)
    {
        ft_puthex(n / 16);
        hex_nbr++;
    }   
    write(1, &hex_letter[n % 16], 1);
    return (hex_nbr);
}
