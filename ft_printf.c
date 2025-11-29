/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:19:29 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/29 13:26:53 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
        va = ft_putunbr(va_arg(args, int));
    if (c == '%')
        va = ft_putchar('%');
    if (c == 'x')
        va = ft_puthex(va_arg(args, int));
    if (c == 'X')
        va = ft_putuphex(va_arg(args, int));
    if (c == 'p')
        va = ft_putptr(va_arg(args, void *));
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
    return (data_type);
}

int main (void)
{
    int what;

    what = 10;

    ft_printf("\n");
    ft_printf("[FT_PRINTF RESULT]\n");
    ft_printf("string: %s\n", "this is string");
    ft_printf("character: %c\n", 'c');
    ft_printf("integer: %i\n", 42);
    ft_printf("decimal: %d\n", 42);
    ft_printf("unsigned int for -1000: %u\n", -1000);
    ft_printf("percentage sign: %%\n");
    ft_printf("hexadecimal x for 45: %x\n", 45);
    ft_printf("hexadecimal X for 45: %X\n", 45);
    ft_printf("memory address is %p", &what);
    ft_printf("\n");
    printf("[STANDARD PRINTF RESULT]\n");
    printf("string: %s\n", "this is string");
    printf("character: %c\n", 'c');
    printf("integer: %i\n", 42);
    printf("decimal: %d\n", 42);
    printf("unsigned int for -1000: %u\n", -1000);
    printf("percentage sign: %%\n");
    printf("hexadecimal x for 45: %x\n", 45);
    printf("hexadecimal X for 45: %X\n", 45);
    printf("memory address is %p", &what);
    printf("\n");
    
    return (0);
}