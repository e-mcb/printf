/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:57:42 by mzutter           #+#    #+#             */
/*   Updated: 2024/11/14 00:00:16 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countdigits(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*uitoa(unsigned int n)
{
	char	*nbr;
	int		len;

	len = countdigits(n);
	nbr = (char *)malloc(len + 1);
	if (!nbr)
		return (NULL);
	nbr[len] = 0;
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		nbr[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (nbr);
}

int	printuint(unsigned int n)
{
	int		len;
	char	*nbr;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		nbr = uitoa(n);
		len += printstrret(nbr);
		free(nbr);
	}
	return (len);
}
