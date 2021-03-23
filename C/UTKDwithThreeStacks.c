#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main() {
    Stack st;
    stack_init(&st);

    Stack max_st;
    stack_init(&max_st);

    Stack min_st;
    stack_init(&min_st);

    int N;
    scanf("%d", &N);

    char command[5];
    for (int i = 0; i < N; i++) {
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            int x;
            scanf("%d", &x);
            
            if (stack_isEmpty(&st)) {
                stack_push(&st, x);
                stack_push(&max_st, x);
                stack_push(&min_st, x);
            }
            else {
                if (x > stack_top(&max_st)) {
                    stack_push(&max_st, x);
                }
                else {
                    stack_push(&max_st, stack_top(&max_st));
                }

                if (x < stack_top(&min_st)) {
                    stack_push(&min_st, x);
                }
                else {
                    stack_push(&min_st, stack_top(&min_st));
                }

                stack_push(&st, x);
            }
        }
        else if (strcmp(command, "pop") == 0) {
            stack_pop(&st);
            stack_pop(&max_st);
            stack_pop(&min_st);
        }
        else if (strcmp(command, "top") == 0) {
            printf("%d\n", stack_top(&st));
        }
        else if (strcmp(command, "max") == 0) {
            printf("%d\n", stack_top(&max_st));
        }
        else if (strcmp(command, "min") == 0) {
            printf("%d\n", stack_top(&min_st));
        }
    }

    // normal   5 6
    // max      5 6
    // min      5 5
    return 0;
}