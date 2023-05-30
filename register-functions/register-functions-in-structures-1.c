#include <stdio.h>

/* structure with an int and a void pointer to be used to point to functions that take an integer input parameter */
struct myStruct_t {
    int a;
    void (*fun) (int *x);
};


/*
*
*/
void get_a(int *a) {
    printf("Pass a value to the registered function, to update 'a': ");
    scanf("%d", a);
}


/*
*
*/
int main() {
    struct myStruct_t myStruct;
    myStruct.a = 0;
    printf("myStruct's 'a' element has the value (before): %d\n", myStruct.a);

    myStruct.fun = get_a; /* assigns the function to the pointer in the structure */
    myStruct.fun(&myStruct.a); /* call the function pointed to by the structure's pointer */
    printf("myStruct's 'a' element has the value (after): %d\n", myStruct.a);
    
    return 0;
}