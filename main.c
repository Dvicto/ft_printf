#include "ft_printf.h"
#include <limits.h>

int main(){
    int i, b;
    long double a;
    i = ft_printf("%f", 0.1);
 /*   ft_printf("%07c", 'a');
    b = printf("end\n%-015.7uend", 15);
    printf("\n%d %d\n", i,b);
    
    ft_printf("%.24lu%llu%u%.2s", 22337203685477, 0ull, 878023, "notall");
    printf("\n%.24lu%llu%u%.2s\n", 22337203685477, 0ull, 878023, "notall");*/
    return 0;
}