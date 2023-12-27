/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 03:29:07 by mmoussou          #+#    #+#             */
/*   Updated: 2023/12/02 04:11:09 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptrprint(unsigned long long value, size_t *l)
{
	if (!value)
	{
		*l += write(1, "(nil)", 5);
		return ;
	}
	*l += write(1, "0x", 2);
	ft_uhexprint(value, "0123456789abcdef", l);
}

void	ft_uhexprint(unsigned long long nbr, char *base, size_t *l)
{
	if (nbr < 16)
		*l += ft_putchar(base[nbr]);
	else
	{
		ft_uhexprint(nbr / 16, base, l);
		*l += ft_putchar(base[nbr % 16]);
	}
}
