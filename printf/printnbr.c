/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:54:05 by mzutter           #+#    #+#             */
/*   Updated: 2024/11/14 01:14:56 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(int n)
{
	size_t	i;

	i = 0;
	if (n == 0 || n == -0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*create_arr(size_t len, long n)
{
	char	*str;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == 0 || n == -0)
		str[0] = '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	len;
	long	nbr;

	i = 0;
	nbr = n;
	len = count_digits(nbr);
	str = create_arr(len, nbr);
	if (!str)
		return (NULL);
	str[len] = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		i++;
	}
	while (nbr != 0)
	{
		str[--len] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (str);
}

int	printnbr(int n)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = ft_itoa(n);
	len = printstrret(nbr);
	free (nbr);
	return (len);
}

// int main ()
// {
//     printf("\n%d\n", printnbr(5403));
// }
