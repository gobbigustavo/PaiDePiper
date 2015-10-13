#define MAX_SIZE 20
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Files/CUnit/Headers/Basic.h"

struct stack {
    int currentSize;
    int itens[MAX_SIZE];
} typedef Stack;

Stack * createStack(){
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->currentSize = 0;
    return stk;
}

Stack * push(int item, Stack * stk){
    if(stk->currentSize >= MAX_SIZE){
        printf("Stack OverFlow!");
        return NULL;
    } else {
        stk->itens[stk->currentSize++] = item;
    }
    return stk;
}
int isEmpty(Stack* stk){
    return stk->currentSize == 0;
}

int peek(Stack* stk){
    if(!isEmpty(stk)){
        return stk->itens[stk->currentSize-1];
    } else {
        return -1;
    }
}

int pop(Stack* stk){
    if(!isEmpty(stk)){
        return stk->itens[--stk->currentSize];
    } else {
        return -1;
    }
}

int destroyStack(Stack* stk){
    while(!isEmpty(stk)){
        pop(stk);
    }
    free(stk);
    return 1;
}

/*Pointer to the Queue used by the tests*/
Stack * stack =  NULL;

int init_suite_stk(void)
{
   if (NULL == (stack = createStack())) {
      return -1;
   }
   else {
      return 0;
   }
}

int clean_suite_queue(void)
{
   return !destroyStack(stack);
}

/* Simple test of push().
 * inserts some data end checks if the top of the stack is
 * the same of the inserted values
 */
void testPush(void)
{
   int i;
   for(i=1; i<=10;i++){
        push(i*3, stack);
        CU_ASSERT( i*3 == peek(stack));
   }
}

void testPop(void)
{
   int i;
   for(i=10; i>=1;i--){
        CU_ASSERT( i*3 == pop(stack));
   }
}

void testPeek(void)
{
    CU_ASSERT( -1 == peek(stack));
    push(0, stack);
    CU_ASSERT( 0 == peek(stack));
    push(9879564, stack);
    CU_ASSERT( 9879564 == peek(stack));
    pop(stack);
    pop(stack);
}


int main(){

    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CU_initialize_registry() != CUE_SUCCESS){
        return CU_get_error();
    }

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_Queue", init_suite_stk, clean_suite_queue);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    /* NOTE - ORDER IS IMPORTANT - THE ORDER
     * THAT THE FUNCTIONS ARE ADDED IS THE ONE
     * THE ONE THAT THEY WILL BE EXECUTED
     */
    if ((NULL == CU_add_test(pSuite, "test of PEEK()", testPush)) ||
        (NULL == CU_add_test(pSuite, "test of PUSH()", testPush)) ||
        (NULL == CU_add_test(pSuite, "test of POP()", testPop)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();

}
