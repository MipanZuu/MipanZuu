//
//  main.c
//  Buying Tickets
//
//  Created by Denta Bramasta Hidayat on 29/03/21.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode   *_front,
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value){
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (queue_isEmpty(queue))
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue){
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);

        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue){
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main(int argc, char const *argv[]){

    Queue ticket_queue;
    queue_init(&ticket_queue);

    int i, n, abc, total_tickets = 0, total_time=0;
    scanf("%d",&n);
    for(i=0;i<n*3;i++){
        scanf("%d",&abc);
        queue_push(&ticket_queue,abc);
    }

    for(i=0;i<n;i++){

        int tickets = 1;
        int curr_lowest = queue_front(&ticket_queue);
        queue_pop(&ticket_queue);

        if(curr_lowest >= queue_front(&ticket_queue)){
            tickets = 2;
            curr_lowest = queue_front(&ticket_queue);
        }
        queue_pop(&ticket_queue);

        if(curr_lowest >= queue_front(&ticket_queue)){
            tickets = 3;
            curr_lowest = queue_front(&ticket_queue);
        }
        queue_pop(&ticket_queue);

        total_time += curr_lowest;
        total_tickets += tickets;

       //  debug
        printf("[%d]\n"
               "curr_lowest     = %d\n"
               "tickets         = %d\n"
               "total_time      = %d\n"
               "total_tickets   = %d\n\n",
               i,curr_lowest,tickets,total_time,total_tickets);

        if(total_tickets == n)
            break;
    }

    printf("%d\n",total_time);

    return 0;
}
