/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:07:04 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/28 16:12:39 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void ft_putaddress(void *n)
{
    
}

int main (void)
{
    int what;
    
    what = 0;
    printf("%p", &what);
    ft_putaddress(&what);
}