#include"Utility.h"

void autofree(void* target) {
    if (target == NULL) return;

    int local;
    int* dynamic = (int*)malloc(sizeof(int));

    int local_adr, dynamic_adr, target_adr;
    local_adr = &local;
    dynamic_adr = dynamic;
    target_adr = target;

    /*printf("local   is : %p\n", local_adr);
    printf("dynamic is : %p\n", dynamic_adr);
    printf("target  is : %p\n", target_adr);*/

    int heap = target_adr - dynamic_adr;
    heap = (heap < 0) ? (-1 * heap) : heap;
    int stack = target_adr - local_adr;
    stack = (stack < 0) ? (-1 * stack) : stack;

    if (stack > heap) free(target);

    free(dynamic);
}
