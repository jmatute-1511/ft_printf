/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:42:50 by jmatute-          #+#    #+#             */
/*   Updated: 2021/07/17 18:55:19 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_string(char *c)
{
	int	count;

	count = 0;
	while (c[count])
		(write(1, &c[count], 1)) && (count++);
	return (count);
}

int	count_digit(int n, int base)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		count = 11;
	else if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n >= base)
	{
		n = n / base;
		count++;
	}
	return (count);
}

void	ft_recursive(int nb)
{
	if (nb == -2147483648)
	{
		nb = nb - 1;
		ft_putchar('-');
		ft_recursive(nb / 10);
		ft_putchar((nb % 10 + 1) + 48);
	}
	else if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-');
		ft_recursive(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else if (nb > 0)
	{
		ft_recursive(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

int	ft_putnbr(int n)
{
	int	a;

	if (n != 0)
	{
		ft_recursive(n);
		a = count_digit(n, 10);
	}
	else
	{
		a = ft_putchar('0');
	}
	return (a);
}
