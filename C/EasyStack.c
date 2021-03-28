//
//  main.c
//  maximumfrequency
//
//  Created by Denta Bramasta Hidayat on 28/03/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *list)
{
    list->_top = NULL;
    list->_size = 0;
}

bool isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void push(Stack *stack, int value)
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
      
        if (isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void pop(Stack *stack)
{
    if (!isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int top(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->_top->data;
    return 0;
}


int main(int argc, const char * argv[]) {
    int a;
    int arr;
    
    Stack myStack;
    stack_init(&myStack);
    
    scanf("%d", &a);
    
   while (a--) {
        int value;
        scanf("%d", &arr);
        
        if (arr == 1) {
            scanf("%d", &value);
            push(&myStack, value);
            
        } else if (arr == 2) {
            pop(&myStack);
        }
        else if (arr == 3){
            if (!isEmpty(&myStack)) {
            printf("%d\n", top(&myStack));
            } else {
                printf("Empty!\n");
            }
        }
    }
    return 0;
}
