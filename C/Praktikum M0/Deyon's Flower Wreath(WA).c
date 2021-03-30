//
//  main.c
//  Praktikum Strukdat modul 0
//
//  Created by Denta Bramasta Hidayat on 29/03/21.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */
char empty_string[] = "";

typedef struct dnode_t {
    char data[1001];
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

DListNode* __dlist_createNode(char *value);
void init(Deque *deque);
bool isEmpty(Deque *deque);
void pushBack(Deque *deque, char *value);
char *front(Deque *deque);
char *back(Deque *deque);
void popBack(Deque *deque);

/* Definition Function */

DListNode* __dlist_createNode(char value[1001])
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    strcpy(newNode->data, value); // copy the value to the newNode->data
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

void pushBack(Deque *deque, char value[1001])
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

char *front(Deque *deque) {
    if (!isEmpty(deque)) {
        return (deque->_head->data);
    }
    return empty_string;
}

char *back(Deque *deque) {
    if (!isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return empty_string;
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

bool DoubleFlowers(Deque *d, char flower[]) {
  DListNode *temp = d->_head;
  while (temp != NULL) {
    if (strcmp(flower, temp->data) == 0)
      return true;
    temp = temp->next;
  }
  return false;
}//check if the input is equals to temp->data then it will be count 1

int main() {
    int a;
    char input[1001];
    
    Deque ada;
    init(&ada);
    
    scanf("%d", &a);
    bool before = false;
   
    for (int i = 0; i<a; i++) {
        scanf("%s", input);
        
        if (strcmp(input, "size")==0) {
            if (isEmpty(&ada)) {
              printf("0\n");
            }
            else {
              printf("%d\n", ada._size);
                while (!isEmpty(&ada)) {
                    popBack(&ada);
                }
            }
        }
        
        else if (strcmp(input, "before")==0) {
            if (isEmpty(&ada)) {
                printf("Deyon, stop!\n");
            }
                else {
                    //popBack(&ada);
                    printf("%s\n", back(&ada));
                }
                before = true;
            }
        else if (strcmp(input, "redo")==0){
            while (!isEmpty(&ada)) {
                popBack(&ada);
            }
        }
        
        char value[1001];
        if (strcmp(input, "add")==0){
            scanf("%s", value);
            if (!DoubleFlowers(&ada, value)) {
              pushBack(&ada, value);
            }
        }
    }
    if (before)
      printf("Pog Flower Wreath\n");
    else
      printf("bad flowers :(\n");
}
