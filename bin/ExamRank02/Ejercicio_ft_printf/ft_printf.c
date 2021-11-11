/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:11:25 by icastell          #+#    #+#             */
/*   Updated: 2021/10/28 16:29:42 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

int	len;

int ft_strlen(const char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnum(long long num, char *base, int base_len)
{
	if (num >= base_len)
		ft_putnum(num / base_len, base, base_len);
	len += write(1, &base[num % base_len], 1);
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	char	*str;
	char	*base;
	int		base_len;
	int		n;
	long	num;
	int		sign;

	i = 0;
	str = NULL;
	base = NULL;
	base_len = 0;
	n = 0;
	num = 0;
	va_start(list, format);
	i = -1;
	len = 0;
	sign = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			sign = 0;
			if (format[i] == 's')
			{
				str = va_arg(list, char *);
				if (!str)
					str = "(null)";
				n = ft_strlen(str);
			}
			if (format[i] == 'd')
			{
				num = va_arg(list, int);
				base = "0123456789";
				base_len = 10;
				if (num < 0)
				{
					num = -num;
					sign = 1;
				}
			}
			if (format[i] == 'x')
			{
				num = va_arg(list, unsigned);
				base = "0123456789abcdef";
				base_len = 16;
			}
			if (sign == 1)
				len += write(1, "-", 1);
			if (format[i] == 's')
				len += write(1, str, n);
			else
				ft_putnum(num, base, base_len);
		}
		else
			len += write(1, &format[i], 1);
	}
	va_end(list);
	return (len);
}

int main()
{
	int	numchar;

	numchar = ft_printf("%d %d %d %d\n", INT_MAX, INT_MIN, 0, -42);
	printf("I: caracteres impresos: %d\n", numchar);
	numchar = printf("%d %d %d %d\n", INT_MAX, INT_MIN, 0, -42);
	printf("O: caracteres impresos: %d\n", numchar);
	numchar = ft_printf("Magic %s is %d\n", "number", 42);
	printf("I: caracteres impresos: %d\n", numchar);
	numchar = printf("Magic %s is %d\n", "number", 42);
	printf("O: caracteres impresos: %d\n", numchar);
	numchar = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("I: caracteres impresos: %d\n", numchar);
	numchar = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("O: caracteres impresos: %d\n", numchar);
	numchar = ft_printf("Hexadecimal for %d is %x\n", -42, -42);
	printf("I: caracteres impresos: %d\n", numchar);
	numchar = printf("Hexadecimal for %d is %x\n", -42, -42);
	printf("O: caracteres impresos: %d\n", numchar);
	numchar = ft_printf("null = %s rrr\n", NULL);
	printf("I: caracteres impresos: %d\n", numchar);
	numchar = printf("null = %s rrr\n", NULL);
	printf("O: caracteres impresos: %d\n", numchar);
	return (0);
}
