/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlane <cadlane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:21:10 by cadlane           #+#    #+#             */
/*   Updated: 2024/01/20 14:42:18 by cadlane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list ap, char c, int *i)
{
	int	res;

	res = 0;
	if (c == 'c')
		res += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		res += ft_putstr(va_arg(ap, char *));
	else if (c == 'X')
		res += ft_putnbr_base(va_arg(ap, unsigned int), HEX_UPPER);
	else if (c == 'x')
		res += ft_putnbr_base(va_arg(ap, unsigned int), HEX_LOWER);
	else if (c == 'p')
		res += ft_putstr("0x") + ft_putnbr_base(va_arg(ap, unsigned long),
				HEX_LOWER);
	else if (c == 'u')
		res += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'd' || c == 'i')
		res += ft_putnbr(va_arg(ap, int));
	else if (c == '%')
		res += ft_putchar('%');
	else
		(*i)--;
	return (res);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		nb;
	int		j;

	va_start(ap, s);
	j = -1;
	nb = 0;
	while (s[++j])
	{
		if (s[j] == '%')
		{
			j++;
			if (!s[j])
				return (nb);
			nb += ft_check(ap, s[j], &j);
		}
		else
			nb += ft_putchar(s[j]);
	}
	va_end(ap);
	return (nb);
}
