#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

static int countdigits(unsigned int n)
{
    int len;

    len = 0;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    return (len);
}

char *uitoa(unsigned int n)
{
    char    *nbr;
    int     len;

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

void    putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int printstrret(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
    {
        putstr("(null)");
        return (6);
    }
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int printuint(unsigned int n)
{
    int len;
    char *nbr;

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

int main ()
{
    printf("\n%d\n", printuint(468));
//    printuint(468);
}

