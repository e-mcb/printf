/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:38 by mzutter           #+#    #+#             */
/*   Updated: 2024/11/14 01:33:37 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(int c)
{
	write (1, &c, 1);
	return (1);
}

static int	printpercent(void)
{
	write (1, "%", 1);
	return (1);
}

int	check_format(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += printchar(va_arg(args, int));
	else if (c == 's')
		len += printstrret(va_arg(args, char *));
	else if (c == 'p')
		len += printptrret(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += printnbr(va_arg(args, int));
	else if (c == 'u')
		len += printuint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += printhexret(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += printpercent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += check_format(args, str[i + 1]);
			i++;
		}
		else
			len += printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
