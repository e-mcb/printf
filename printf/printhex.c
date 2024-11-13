#include "ft_printf.h"
#include <stdio.h>

int hexlen(unsigned int n)
{
    int len;

    len = 0;
    while (n != 0)
    {
        len++;
        n /= 16;
    }
    return (len);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void puthex(unsigned int n, const char c)
{
    if (n >= 16)
    {
        puthex(n / 16, c);
        puthex(n % 16, c);
    }
    else
    {
        if (n <= 9)
            ft_putchar_fd((n + 48), 1);
        else
        {
        if (c == 'x')
            ft_putchar_fd((n - 10 + 'a'), 1);
        if (c == 'X')
            ft_putchar_fd((n - 10 + 'A'), 1);
        }
    }
}

int printhexret(unsigned int n, const char c)
{
    if (n == 0)
        return (write(1, "0", 1));
    else
        puthex(n, c);
    return (hexlen(n));
}