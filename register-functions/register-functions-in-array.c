#include <stdio.h>


/*
*/
void fun1(void) {
    printf("Hello from fun1.\n");
}

/*
*/
void *fun2(void) {
    printf("Hello from fun2.\n");
}

/*
*/
void fun3(void) {
    printf("Hello from fun3.\n");
}

/*
*/
void fun4(int *x) {
    printf("Hello from fun4.\n");
    int tmp = 3;
    printf("  setting x to %d\n", tmp);
    *x = tmp;
}

/*
*/
void fun5(int *x) {
    printf("Hello from fun5.\n");
    printf("  a is now %d\n", *x);
}

/*
*/
int fun6(int *x) {
    printf("Hello from fun6.\n");
    int a_squared = *x;
    a_squared = a_squared * a_squared;
    return a_squared;
}

/*
*
*/
int main(void) {
    /* fun1 */
    void (*arrayOfFun1[256])(); /* array of pointers to functions that take unspecified numbers or types of arguments and returns nothing */
    arrayOfFun1[0] = fun1;
    arrayOfFun1[0]();
    printf("  ----> start of: arrayOfFun1 with another type of function registered.\n");
    arrayOfFun1[1] = fun4; /* notice that here we prove that we can register a function of the same type but different number of arguments and types of arguments */
    int a0 = 6;
    arrayOfFun1[1](&a0);
    printf("  ----> end of: arrayOfFun1 with another type of function registered.\n");

    /* fun2 */
    void *(*arrayOfFun2[256])(); /* array of pointers to function pointers that take unspecified numbers or types of arguments and returns nothing */
    arrayOfFun2[0] = fun2;
    arrayOfFun2[0]();

    /* fun3 */
    void (*arrayOfFun3[256])(void); /* array of pointers to functions that take nothing and return nothing */
    arrayOfFun3[0] = fun3;
    arrayOfFun3[0]();

    /* fun4 */
    void (*arrayOfFun4[256])(int *x); /* array of pointers to functions that take one pointer to 'int' and return nothing */
    arrayOfFun4[0] = fun4;
    int a;
    arrayOfFun4[0](&a);
    
    /* fun5 */
    void (*arrayOfFun5[256])(int *x); /* array of pointers to functions that take one pointer to 'int' and return nothing */
    arrayOfFun5[0] = fun5;
    arrayOfFun5[0](&a);

    /* fun6 */
    int (*arrayOfFun6[256])(int *x); /* array of pointers to functions that take one pointer to 'int' and return a pointer to 'int' */
    arrayOfFun6[0] = fun6;
    int a_squared = arrayOfFun6[0](&a);
    printf("  'a' squared is %d\n", a_squared);

    return 0;
}