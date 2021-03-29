//
//  main.c
//  ADAQueue
//
//  Created by Denta Bramasta Hidayat on 28/03/21.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */
bool isReverse = false;

typedef struct dnode_t {
    int data;
    struct dnode_t
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */

typedef struct deque_t {
    DListNode
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
        else {
        if (isReverse == false) {
            newNode->next = deque->_head;
            deque->_head->prev = newNode;
        }
        else {
            newNode->prev = deque->_head;
            deque->_head->next = newNode;
        }
        deque->_head = newNode;
        }
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
        else {
        if (isReverse == false) {
            deque->_tail->next = newNode;
            newNode->prev = deque->_tail;
        }
        else {
            deque->_tail->prev = newNode;
            newNode->next = deque->_tail;
        }
        
        deque->_tail = newNode;
        }
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
            if (isReverse == false) {
                deque->_head = deque->_head->next;
                deque->_head->prev = NULL;
            }
            else{
                deque->_head = deque->_head->prev;
                deque->_head->next = NULL;
            }
           
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
            if (isReverse == false) {
                deque->_tail = deque->_tail->prev;
                deque->_tail->next = NULL;
            }
            else{
                deque->_tail = deque->_tail->next;
                deque->_tail->prev = NULL;
            }
            free(temp);
        }
        deque->_size--;
    }
}

void reverse(Deque *deque) {
        DListNode *temp = deque->_head;
        deque->_head = deque->_tail;
        deque->_tail = temp;
}


int main(int argc, const char * argv[]) {
    int a;
    char input[1001];
    
    Deque ada;
    init(&ada);
    
    scanf("%d", &a);
    //for (int i = 0; i<=a; i++) {
    for (int i = 0; i<a; i++) {
        scanf("%s", input);
        
        if (strcmp(input, "back")==0) {
            if (isEmpty(&ada)) {
                printf("No job for Ada?\n");
            }
                else {
                    printf("%d\n", back(&ada));
                    popBack(&ada);
                
            }
        }
        
        else if (strcmp(input, "front")==0) {
            if (isEmpty(&ada)) {
                printf("No job for Ada?\n");
            }
                else {
                    printf("%d\n", front(&ada));
                    popFront(&ada);
                    
                }
            }
            
        int value;
        if (strcmp(input, "reverse")==0){
            reverse(&ada);
            if (isReverse == false){
                isReverse = true;
            } isReverse = false;
        }
        
        else if (strcmp(input, "push_back")==0){
            scanf("%d\n", &value);
                pushBack(&ada, value);
        }
        else if (strcmp(input, "toFront")==0){
                scanf("%d\n", &value);
                    pushFront(&ada, value);
            }
    }
}
