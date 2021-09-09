/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:19:26 by jmatute-          #+#    #+#             */
/*   Updated: 2021/07/17 18:54:47 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(const char *s, t_format *frmt, va_list args)
{
	int	a;

	a = 0;
	frmt->d = va_arg(args, int);
	if (*(s + 1) == 'c')
		a = ft_putchar((char)frmt->d);
	else
		a = ft_putnbr((int)frmt->d);
	return (a);
}

int	print_hexa(const char *s, t_format *frmt, va_list args)
{
	int	a;

	a = 0;
	if (*(s + 1) == 'p')
		frmt->x = va_arg(args, unsigned long int);
	else
		frmt->x = va_arg(args, unsigned int);
	if (*(s + 1) == 'x')
		a = ft_putnbr_base(frmt->x, "0123456789abcdef", 16);
	else if (*(s + 1) == 'X')
		a = ft_putnbr_base(frmt->x, "0123456789ABCDEF", 16);
	else if (*(s + 1) == 'u')
		a = ft_putnbr_base(frmt->x, "0123456789", 10);
	else
	{
		write(1, &"0x", 2);
		a = 2 + ft_putnbr_base(frmt->x, "0123456789abcdef", 16);
	}
	return (a);
}

int	print_simple_format(const char *s, t_format *frmt, va_list args)
{
	int	a;

	a = 0;
	if (*(s + 1) == 'd' || *(s + 1) == 'i' || *(s + 1) == 'c')
		a = print_int(s, frmt, args);
	else if (*(s + 1) == 'p' || *(s + 1) == 'x' || *(s + 1) == 'X' \
	|| *(s + 1) == 'u')
		a = print_hexa(s, frmt, args);
	else if (*(s + 1) == '%')
		a = ft_putchar('%');
	else if (*(s + 1) == 's')
	{
		frmt->aux = va_arg(args, char *);
		a = ft_putchar_string(frmt->aux);
	}
	return (a);
}

int	back_ft_printf(const char *s, t_format *frmt, va_list args)
{
	int	a;

	a = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			a += print_simple_format(s, frmt, args);
			s++;
		}
		else
			a++ && ft_putchar(*s);
		s++;
	}
	return (a);
}

int	ft_printf(const char *s, ...)
{
	t_format	format;
	t_format	*frmt;
	va_list		args;
	int			a;

	frmt = &format;
	va_start(args, s);
	a = back_ft_printf(s, frmt, args);
	va_end(args);
	return (a);
}
