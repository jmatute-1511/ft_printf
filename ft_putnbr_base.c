/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:22:17 by jmatute-          #+#    #+#             */
/*   Updated: 2021/09/09 17:45:28 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(size_t nbr, char *base, size_t lenbase)
{
	static int	a;

	a = 0;
	if (nbr >= lenbase)
		ft_putnbr_base(nbr / lenbase, base, lenbase);
	a++;
	write(1, &base[nbr % lenbase], 1);
	return (a);
}
