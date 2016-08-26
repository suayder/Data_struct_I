#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Q{
    int A;
    struct Q *prox;
}typequeue;
typequeue *front, *rear;
int size_queue;
void start(){
    //queue=(typequeue*) malloc(sizeof(typequeue));
    front=NULL;
    rear=NULL;
    //queue->prox=NULL;
    size_queue=0;
}
int insert_queue(int value){
    typequeue *newbox=(typequeue*) malloc(sizeof(typequeue));
    if(newbox==NULL){
        printf("\nQueue overflow!");
        return 0;
    }
    if(front==NULL){
        newbox->A=value;
        newbox->prox=NULL;
        front=newbox;
        rear=newbox;
    }
    else{
        newbox->A=value;
        newbox->prox=NULL;
        rear->prox=newbox;
        rear=rear->prox;
    }
    size_queue++;
    return 1;
}
int remove_queue(){
    typequeue *aux;
    int V;
    if(front==NULL){
        printf("\nQueue underflow!");
        return 0;
    }
    aux=front;
    V=front->A;
    front=front->prox;
    aux->prox=NULL;
    free(aux);
    size_queue--;
    return V;
}
void print_queue(){
    typequeue *aux=front;
    for(aux;aux!=NULL;aux=aux->prox) printf("aux: %d\n", aux->A);
}
int left(int i){
    return(2*i);
}
int right(int i){
    return (2*i+1);
}
int build_MAX_heap(int i){

}
int heapify(int i){
    int l, r, larger, aux=0;
    typequeue *heap_aux=front;
    l=left(i);
    r=right(i);
    larger=i;
    while(aux<l){
        heap_aux=heap_aux->prox;
        aux++;
    }
    if(l<size_queue && )
}
int main()
{
    int value;
    start();
    srand(time(NULL));
    for(value=0;value<=5;value++){
        insert_queue((rand()%100));
    }
    print_queue();
    printf("REMOVE:%d\n", remove_queue());
    remove_queue();
    print_queue();
    return 0;
}
