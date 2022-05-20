/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:47:15 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/31 12:28:13 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

static void	detectformat(const char *str, int pos, va_list args)
{
	if (str[pos] == 'c')
		ft_putchar(va_arg(args, int));
	else if (str[pos] == 's')
		ft_putstr(va_arg(args, char *));
	else if (str[pos] == 'd' || str[pos] == 'i')
		ft_putnbr(va_arg(args, int));
}

void	ft_printf(const char *format, ...)
{
	int		i;
	va_list	paramsinfos;

	va_start(paramsinfos, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			detectformat(format, i + 1, paramsinfos);
			i++;
		}
		i++;
	}
	va_end(paramsinfos);
}
