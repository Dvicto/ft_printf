#include "printf.h"
#include <limits.h>

int main(){
    int i, b;
    i = ft_printf("% u", 429496);
    b = printf("\n% u", 429496);
    printf("\n%d %d", i,b);
    /*
    ft_printf("%.24lu%llu%u%.2s", 22337203685477, 0ull, 878023, "notall");
    printf("\n%.24lu%llu%u%.2s\n", 22337203685477, 0ull, 878023, "notall");*/
    return 0;
}