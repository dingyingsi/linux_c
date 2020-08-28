#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {


        const int size = 20000;
        int *p = (int *)malloc(20*sizeof(int));
        int *pp = (int *)realloc(p, size*sizeof(int));

        printf("原来的p_Address:%x   扩容后的pp_Address:%x \n\n", p, pp);


    return EXIT_SUCCESS;
}
