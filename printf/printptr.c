/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:55:55 by mzutter           #+#    #+#             */
/*   Updated: 2024/11/14 02:12:59 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptrlen(uintptr_t n)
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

void	putptr(uintptr_t n)
{
	if (n >= 16)
	{
		putptr(n / 16);
		putptr(n % 16);
	}
	else
	{
		if (n <= 9)
			printchar((n + 48));
		else
			printchar((n - 10 + 'a'));
	}
}

int	printptrret(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		putptr(ptr);
		len += ptrlen(ptr);
	}
	return (len);
}
