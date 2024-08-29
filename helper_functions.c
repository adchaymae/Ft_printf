/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlane <cadlane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:22:25 by cadlane           #+#    #+#             */
/*   Updated: 2024/01/20 14:53:42 by cadlane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr(int nb)
{
	int	res;

	res = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		res += write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		res += ft_putnbr(nb / 10);
		res += ft_putnbr(nb % 10);
	}
	else
		res += ft_putchar(nb + 48);
	return (res);
}

int	ft_putnbr_base(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= (unsigned long)ft_strlen(base))
		count += ft_putnbr_base(nb / ft_strlen(base), base);
	count += ft_putchar(base[nb % ft_strlen(base)]);
	return (count);
}
