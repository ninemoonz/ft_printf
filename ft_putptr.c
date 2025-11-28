/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:07:04 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/28 16:44:13 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putptr(void *ptr)
{
    unsigned long long addr;
    int count;

    if(!ptr)
        return (write(1, "(nil)", 5));
    count = 0;
    write(1, "0x", 2);
    count++;
    addr = (unsigned long long)ptr;
    count = ft_puthex(addr);
    count++;
    return count;
}

