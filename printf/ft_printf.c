/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:46:39 by mmoussou          #+#    #+#             */
/*   Updated: 2023/12/18 15:57:56 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_arg(va_list argsl, char type, size_t *l)
{
	if (type == 'c')
		*l += ft_putchar(va_arg(argsl, int));
	else if (type == 's')
		*l += ft_putstr(va_arg(argsl, char *));
	else if (type == 'p')
		ft_ptrprint(va_arg(argsl, unsigned long long), l);
	else if (type == 'd' || type == 'i')
		*l += ft_putnbr(va_arg(argsl, int));
	else if (type == 'u')
		*l += ft_putnbr(va_arg(argsl, unsigned int));
	else if (type == 'x')
		ft_uhexprint(va_arg(argsl, unsigned int), "0123456789abcdef", l);
	else if (type == 'X')
		ft_uhexprint(va_arg(argsl, unsigned int), "0123456789ABCDEF", l);
	else if (type)
	{
		*l += ft_putchar('%');
		if (type != '%')
			*l += ft_putchar(type);
	}
	else
		*l = -1;
}

int	ft_printf(const char *str, ...)
{
	va_list	argsl;
	size_t	i;
	size_t	l;

	if (!str)
		return (-1);
	va_start(argsl, str);
	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] == '%')
			print_arg(argsl, str[++i], &l);
		else
			l += ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	va_end(argsl);
	return (l);
}
