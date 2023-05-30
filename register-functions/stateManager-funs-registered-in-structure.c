#include <stdio.h>

/* https://www.freecodecamp.org/news/structured-data-types-in-c-explained */


/* Custom data type definitions */
/* if we use the 'typedef' keyword, then we don't need to specify 'struct stateManager_t stMng1' during declaration */
typedef struct {
    int state;
    int *(*getState) (int *state); /* pointer to a function that takes a pointer to an integer as input parameter and returns a pointer to int */
    void *(*setState) (int *state, int *targetState); /* pointer to a function that takes two pointers to integers as input parameters and returns nothing */
} stateManager_t;

stateManager_t stateMng1, stateMng2, stateMng3, stateMng4;


/* Function prototypes */
int *getModuleState(int *state);
void *setModuleState(int *state, int *targetState);
void registerFunctions(stateManager_t *stateMng);


/*
*
*/
int main(void) {
    /* First example with stateMng1 */
    /* stateManager_t stateMng1; --> this is not recommended,
    better declare it at the beginning of the file*/
    registerFunctions(&stateMng1);
    {
        /* Get state's value at initialization */
        int *state = stateMng1.getState(&stateMng1.state);
        /* Force a state transition */
        int stateMng1_targetState = 11;
        stateMng1.setState(&stateMng1.state, &stateMng1_targetState);
        /* Check the state transition */
        state = stateMng1.getState(&stateMng1.state);
    }


    /* Second example with stateMng2 */
    /* stateManager_t stateMng2; --> this is not recommended,
    better declare it at the beginning of the file*/
    registerFunctions(&stateMng2);
    {
        /* Get state's value at initialization */
        int *state = stateMng2.getState(&stateMng2.state);
        /* Force a state transition */
        int stateMng2_targetState = 22;
        stateMng2.setState(&stateMng2.state, &stateMng2_targetState);
        /* Check the state transition */
        state = stateMng2.getState(&stateMng2.state);
    }


    /* Second example with stateMng3 */
    /* stateManager_t stateMng3; --> this is not recommended,
    better declare it at the beginning of the file*/
    registerFunctions(&stateMng3);
    {
        /* Get state's value at initialization */
        int *state = stateMng3.getState(&stateMng3.state);
        /* Force a state transition */
        int stateMng3_targetState = 33;
        stateMng3.setState(&stateMng3.state, &stateMng3_targetState);
        /* Check the state transition */
        state = stateMng3.getState(&stateMng3.state);
    }

    return 0;
}

/*
*
*/
int *getModuleState(int *state) {
    return state;
}


/*
*
*/
void *setModuleState(int *state, int *targetState) {
    *state = *targetState;
}


/*
*
*/
void registerFunctions(stateManager_t *stateMng) {
    stateMng->getState = getModuleState;
    stateMng->setState = setModuleState;
}
