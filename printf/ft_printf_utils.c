/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 05:53:19 by mmoussou          #+#    #+#             */
/*   Updated: 2023/12/18 15:56:41 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr(long long n)
{
	if (n == -9223372036854775807)
		return (ft_putstr("-9223372036854775807"));
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (ft_putnbr(n / 10) + ft_putchar((n % 10) + '0'));
}
