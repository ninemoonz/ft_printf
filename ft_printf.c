/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:19:29 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/27 16:36:27 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// for va_list, va_start, va_arg, va_end functions

int type_specifier(va_list args, char c)
{
	int	va;

	va = 0;
    if (c == 's')
        va = ft_putstr(va_arg(args, char *));
    if (c == 'c')
        va = ft_putchar(va_arg(args, int));
    if (c == 'i' || c == 'd')
        va = ft_putnbr(va_arg(args, int));
    if (c == 'u')
        va = ft_putunbr(va_arg(args, unsigned int));
    return (va);
}

int ft_printf(const char *format, ...)
{
    va_list args; 
	int i;
    int data_type;

	va_start(args, format);
	i = 0;
    data_type = 0;
	while (format[i])
	{
		if (format[i] == '%')
        {
            if (format[i + 1] != '\0')
            {
                data_type = type_specifier(args, format[i + 1]);
                i++;
            }
        }
        else
            data_type += ft_putchar(format[i]);
        i++;
	}
    va_end(args);
    return (0);
}

int main (void)
{
    char *nine = "nine";
    char c = 'c';
    int nbr = 123;
    unsigned int unbr = -123;

	ft_printf("hello %s, %c, %i, %d, %u", nine, c, nbr, nbr, unbr);
    return (0);
}