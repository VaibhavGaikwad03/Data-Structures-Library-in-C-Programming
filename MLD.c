#include "MLD.h"
#include <stdio.h>

struct data_base_rec d;
 
int main(void)
{
    printf("%d\n", GET_OFFSET(d, size));

    return 0;
}
