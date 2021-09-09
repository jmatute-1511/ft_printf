/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:27:55 by jmatute-          #+#    #+#             */
/*   Updated: 2021/09/05 16:27:55 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_format
{
	int				d;
	char			*aux;
	size_t			x;
}				t_format;

int		ft_putchar(char c);
int		ft_putchar_string(char *c);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int n);
int		ft_putnbr_base(size_t nbr, char *base, size_t lenbase);
int		ft_printf(const char *s, ...);
#endif