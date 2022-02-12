#ifndef Queue_h
#define Queue_h
#include <stdlib.h>
typedef struct node{
    struct node* next;
    int order_number;
    int qty;
}order;

typedef struct {
    order *head,*tail;
    int size;
}Queue;


void enqueue(Queue *q,int ord,int qty){
    order* new_node=(order*)malloc(sizeof(order));
    if(new_node){
        new_node->next=NULL;
        new_node->order_number=ord;
        new_node->qty=qty;
        if(q->head)/*q->size>0*/
            q->tail->next=new_node;
        else
            q->head=new_node;
        q->tail=new_node;
        q->size++;
    }
}

int  dequeue(Queue *q){
    if(q->size==0) {
        printf("No queue");
        return 0;
    }
    
    order *t =q->head;
    int x=t->order_number;
    q->head=q->head->next;
    if(!q->head) q->tail=NULL;
    q->size--;
    free(t);
    return x;
    
}
#endif /* Queue_h */