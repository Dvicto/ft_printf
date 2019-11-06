#include "printf.h"
#include <limits.h>

int main(){
    
    ft_printf("%.5p", 0);
    printf("end\n%.5p", 0);

    /*
    ft_printf("%.24lu%llu%u%.2s", 22337203685477, 0ull, 878023, "notall");
    printf("\n%.24lu%llu%u%.2s\n", 22337203685477, 0ull, 878023, "notall");*/
    return 0;
}