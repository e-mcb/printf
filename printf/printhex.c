/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:57:03 by mzutter           #+#    #+#             */
/*   Updated: 2024/11/14 01:22:52 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	puthex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		puthex(n / 16, c);
		puthex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			printchar((n + 48));
		else
		{
			if (c == 'x')
				printchar((n - 10 + 'a'));
			if (c == 'X')
				printchar((n - 10 + 'A'));
		}
	}
}

int	printhexret(unsigned int n, const char c)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		puthex(n, c);
	return (hexlen(n));
}

/*int main()
{
    printhexret(684515, 'x');
    return 0;
}*/
