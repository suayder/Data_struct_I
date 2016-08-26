#include <stdio.h>
#include <stdlib.h>
#define MAX 3
typedef struct{
    int front;
    int rear;
    int values[MAX];
}box;
box queue;
void start(){
    queue.rear=-1;
    queue.front=0;
}
int queue_insert(int *data){
    if(queue.rear==-1 && queue.front==0){
        queue.rear++;
        queue.values[queue.rear]=*data;
        return 1;
    }
    queue.rear++;
    if(queue.rear%MAX==queue.front%MAX){
        printf("stack overflow");
        return 0;
    }
    int pos=(queue.rear)%MAX;
    queue.values[pos]=*data;
    return 1;
}
int queue_remove (int *data){
    if(queue.rear==-1 && queue.front==0){
        printf("queue underflow");
        return 0;
    }
    int pos=queue.front%MAX;
    *data=queue.values[pos];
    queue.values[pos]=0;
    queue.front++;
    if(queue.front>queue.rear) start();
    return 1;
}
    /*int prox;
    prox=(q->rear+1)%MAX;
    if(prox!=q->front){
        q->values[prox]=dado;
        q->rear=prox;
        if(q->front==-1) q->front=0;
        return 1;
    }
    printf("overflow");
    return 0;
}
int queue_remove(queue *q, int *dado){
    int prox;

    if(q->front==-1){
        printf("underflow");
        return 0;
    }
    prox=(q->front+1)%MAX;
    *dado=q->values[q->front];
    q->values[q->front]=0;
    if(prox > (q->rear)){
        q->rear=-1;
        q->front=-1;
    }
    else q->front=prox;
    printf("FFF:%d\n", q->front);
    printf("RRR:%d\n", q->rear);
    return 1;
}*/
int main()
{
    int data,i,aux;
    start();
    while(1){
        printf("\n1-INSERIR\n0-REMOVER\nOPCAO:");
        scanf("%d",&aux);
        if(aux==1){
            printf("valor:");
            scanf("%d",&data);
            queue_insert(&data);
        }
        else if(aux==0){
            queue_remove(&data);
        }
        else{
            for(i=0;i<MAX;i++){
                printf("V:%d\n", queue.values[i]);
            }
        }
    }

    return 0;
}
