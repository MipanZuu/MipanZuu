//
//  main.c
//  Praktikum Strukdat modul 0
//
//  Created by Denta Bramasta Hidayat on 29/03/21.
//



#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct pqueueNode_t {
    int data;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void init(PriorityQueue *pqueue);
bool isEmpty(PriorityQueue *pqueue);
void push(PriorityQueue *pqueue, int value);
void pop(PriorityQueue *pqueue);
int  top(PriorityQueue *pqueue);

/* Function definition below */

void init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pushAsce(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL &&
                temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pushDesce(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value > pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL &&
                temp->next->data > value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void pop(PriorityQueue *pqueue)
{
    if (!isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int top(PriorityQueue *pqueue) {
    if (!isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}


    int main()
    {
    PriorityQueue Even, Odd;
    init(&Even);
    init(&Odd);
        
        int X, N;
        
        scanf("%d", &X);
        
        while (X--) {
            scanf("%d", &N);
            if(N%2 == 0){//Even Number
                pushAsce(&Even, N);
            }else{              //else Odd Number
                pushDesce(&Odd, N);
            }
        }
            while (!isEmpty(&Even)) {//print Even with Asce
                printf("%d\n", top(&Even));
                pop(&Even);
                }
            while (!isEmpty(&Odd)){//print Odd with Desce
                printf("%d\n", top(&Odd));
                pop(&Odd);
                }
        return 0;
    }
