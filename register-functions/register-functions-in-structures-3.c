#include <stdio.h>

/* structure with an int and a void pointer to be used to point to functions that take an integer input parameter */
struct myStruct_t {
    int a;
    int (*fun1) (void);
    void (*fun2) (int x1, int *x2);
};


/*
*
*/
int getUserValue(void) {
    printf("Pass a value to the registered function, to update 'a': ");
    int userValue;
    scanf("%d", &userValue); /* writes the user's input value to the address pointed to by 'y'*/
    return userValue;
}

/*
*
*/
void update_a(int userValue, int *x3) {
    *x3 = userValue;
}


/*
*
*/
int main(void) {
    struct myStruct_t myStruct;
    myStruct.a = 0;
    printf("myStruct's 'a' element has the value (before): %d\n", myStruct.a);

    myStruct.fun1 = getUserValue; /* assigns the function to the pointer in the structure */
    myStruct.fun2 = update_a; /* assigns the function to the pointer in the structure */
    int userValue = myStruct.fun1(); /* call the function pointed to by the structure's pointer */
    myStruct.fun2(userValue, &myStruct.a); /* call the function pointed to by the structure's pointer */
    printf("myStruct's 'a' element has the value (after): %d\n", myStruct.a);
    
    return 0;
}