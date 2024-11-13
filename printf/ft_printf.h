#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

char *uitoa(unsigned int n);
void    putstr(char *str);
int printstrret(char *str);
int printnbr(int n);
int printuint(unsigned int n);
#endif