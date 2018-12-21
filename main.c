#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
    ft_printf("%jx\n", 4294967295);
    printf("%jx", 4294967295);
}