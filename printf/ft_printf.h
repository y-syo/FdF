/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:29:18 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/17 04:05:39 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	ft_unbrprint(unsigned long long n);
void	ft_ptrprint(unsigned long long value, size_t *l);
void	ft_uhexprint(unsigned long long nbr, char *base, size_t *l);

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(long long n);

#endif
