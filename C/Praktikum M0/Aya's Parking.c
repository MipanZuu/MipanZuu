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

typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;


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

void push(PriorityQueue *pqueue, int value)
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

int main (){
    PriorityQueue carin, carout;
    init(&carin);
    init(&carout);
    
    bool parked = false;
    int N, C, time;
    int I[10001], O[1001];
    int counter = 0;
    
    scanf("%d %d", &N, &C);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &I[i], &O[i]);
        push(&carin, I[i]);
        push(&carout, O[i]);
    }
    for (time = 0; time < 24; time++) {
        if (time == top(&carin)) {
            counter++;
            pop(&carin);
        }
        else if (time == top(&carout)){
            counter--;
            pop(&carout);
        }
        if (counter > C) {
            parked = true;
            break;
        }
    }
    if (parked == true) {
        printf("Macet");
    }
    else {
        printf("Lancar");
    }
    return 0;
    
}
