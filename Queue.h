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

//1 Ramen 60
//2 Sandwich 25 
//3 Boat Noodles 15

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

int dequeue(Queue *q){
    if(q->size==0) {
        printf("No queue");
        return 0;
    }
    order *t =q->head;
    int x=t->order_number;
    int net;
    switch(x){
      case 1:
        net=t->qty*60;
        break;
      case 2:
        net=t->qty*25;
        break;
      case 3:
        net=t->qty*15;
        break;
    }
    q->head=q->head->next;
    if(!q->head) q->tail=NULL;
    q->size--;
    free(t);
    return net;
    
}
#endif /* Queue_h */