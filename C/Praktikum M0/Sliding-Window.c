//
//  main.c
//  Praktikum Strukdat modul 0
//
//  Created by Denta Bramasta Hidayat on 29/03/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */

typedef struct deque_t {
    DListNode           \
        *_head,
        *_tail;
    unsigned _size;
} Deque;


/* List of Functions */

DListNode* __dlist_createNode(int value);
void init(Deque *deque);
bool isEmpty(Deque *deque);
void pushFront(Deque *deque, int value);
void pushBack(Deque *deque, int value);
int  front(Deque *deque);
int  back(Deque *deque);
void popFront(Deque *deque);
void popBack(Deque *deque);
void reverse(Deque *deque);

/* Definition Function */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}

void pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
       if (newNode) {
           deque->_size++;
           if (isEmpty(deque)) {
               deque->_head = newNode;
               deque->_tail = newNode;
               return;
           }

           newNode->next = deque->_head;
           deque->_head->prev = newNode;
           deque->_head = newNode;
       }
   }

void pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
        if (newNode) {
            deque->_size++;
            if (isEmpty(deque)) {
                deque->_head = newNode;
                deque->_tail = newNode;
                return;
            }

            deque->_tail->next = newNode;
            newNode->prev = deque->_tail;
            deque->_tail = newNode;
        }
    }

int front(Deque *deque) {
    if (!isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

int back(Deque *deque) {
    if (!isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void popFront(Deque *deque)
{
    if (!isEmpty(deque)) {
           DListNode *temp = deque->_head;
           if (deque->_head == deque->_tail) {
               deque->_head = NULL;
               deque->_tail = NULL;
               free(temp);
           }
           else {
               deque->_head = deque->_head->next;
               deque->_head->prev = NULL;
               free(temp);
           }
           deque->_size--;
       }
   }

void popBack(Deque *deque)
{
    if (!isEmpty(deque)) {
            DListNode *temp;
            if (deque->_head == deque->_tail) {
                temp = deque->_head;
                deque->_head = NULL;
                deque->_tail = NULL;
                free(temp);
            }
            else {
                temp = deque->_tail;
                deque->_tail = deque->_tail->prev;
                deque->_tail->next = NULL;
                free(temp);
            }
            deque->_size--;
        }
    }


void PrintTheWindow(int arr[], int n, int k)
{
 
    Deque sliding;
    init(&sliding);
 
    
    int i;
    for (i = 0; i < k; ++i)
    {
    while ((!isEmpty(&sliding)) && arr[i] >= arr[back(&sliding)])
        popBack(&sliding);
        pushBack(&sliding,i);
    }
    for (; i < n; ++i)
    {
        printf("%d ", arr[front(&sliding)]);
        
        while ((!isEmpty(&sliding)) && front(&sliding) <= i - k)
            popFront(&sliding);
        
        while ((!isEmpty(&sliding)) && arr[i] >= arr[back(&sliding)])
            popBack(&sliding);
            pushBack(&sliding,i);
}

    printf("%d ",arr[front(&sliding)]);
}
            /*maximum = arr[i];
            for(j = 1; j < K; j++)
            {
                  if(arr[i + j] > maximum)
                  {
                        maximum = arr[i + j];
                  }
            }
            printf("%d ", maximum); */

    int main()
    {
    Deque sliding;
    init(&sliding);
        
        int N, K, arr[101];
        
        scanf("%d", &N);
        scanf("%d", &K);
        for (int a = 0; a < N; a++) {
            scanf("%d", &arr[a]);
    }
        PrintTheWindow(arr, N, K);
        return 0;
}
