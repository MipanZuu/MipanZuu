 //
//  main.c
//  test test
//
//  Created by Denta Bramasta Hidayat on 23/03/21.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

int top(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->_top->data;
    return 0;
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


int main()
{
    Stack car;
    stack_init(&car);
    bool tr = true;
    
    while (1) {
        int a, arr[1001];
        
        scanf("%d", &a);
        if (a == 0) {
            return 0;
        }
        int counter = 1;
        for (int i = 1; i <= a; i++) {
            scanf("%d", &arr[i]);
        
            if (arr[i] == counter) {
                counter++;
            }
            else{
                while (!isEmpty(&car) && top(&car) == counter) {
                    pop(&car);
                    counter++;
                }
                while (!isEmpty(&car) && top(&car) < arr[i]) {
                    tr = false;
                    break;
                }
                push(&car, arr[i]);
            }
        
        }
        if (tr) {
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    
}
