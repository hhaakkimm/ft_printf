#include "includes/ft_printf.h"
#include <stdio.h>

int main(){
    int a = 15;
    printf("{%.*d}\n", -5, 42);
    ft_printf("{%.*d}\n", -5, 42);
    printf("%X %X %X %X %X\n", 1, 100, 999, 42, 999988888);
    ft_printf("%X %X %X %X %X\n", 1, 100, 999, 42, 999988888);
    printf("%u %u %u %u %u\n", 1, 100, 999, 42, 999988888);
    ft_printf("%u %u %u %u %u\n", 1, 100, 999, 42, 999988888);
    printf("%x %x %x %x %x\n", 1, 100, 999, 42, 999988888);
    ft_printf("%x %x %x %x%x", 1, 100, 999, 42, 999988888);
}