/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:59:23 by mzutter           #+#    #+#             */
/*   Updated: 2024/11/14 00:56:07 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

char	*uitoa(unsigned int n);
void	putstr(char *str);
int		printstrret(char *str);
int		printnbr(int n);
int		printuint(unsigned int n);
int		printchar(int c);
#endif
