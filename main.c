#include "ft_printf.h"
#include <limits.h>

int main(){
    int i, b;
    long double a;
    i = ft_printf("%-05");
    b = printf("end\n%.dend", 0);
    printf("\n%d %d\n", i,b);
    
    /*ft_printf("%.24lu%llu%u%.2s", 22337203685477, 0ull, 878023, "notall");
    printf("\n%.24lu%llu%u%.2s\n", 22337203685477, 0ull, 878023, "notall");*/
    return 0;
}