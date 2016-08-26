#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 7
typedef struct{
    int heap_size;
    int A[MAX];
}typeheap;
int left(int i){
    return (i*2);
    }
int right(int i){
    return (i*2+1);
    }
int change(int *value1, int *value2){
    int aux;
    //printf("V1: %d\nV2: %d\n", value1, value2);
    aux=*value1;
    *value1=*value2;
    *value2=aux;
    return 1;
}
int heapify(int i, typeheap *H){
    int l, r, maior;
    l=left(i);
    r=right(i);
    maior=i;
    //printf("L: %d\nR: %d\nM: %d\n", l,r,maior);
    if(l<=H->heap_size && H->A[maior]<H->A[l]) maior=l;
    if(r<=H->heap_size && H->A[maior]<H->A[r]) maior=r;
    if(i!=maior){
        change(&(H->A[i]),&(H->A[maior]));
        heapify(maior,H);
    }
    return 1;
}
int build_Max_heap(typeheap *H){
    int i;
    for(i=(floor(H->heap_size/2));i>=0;i--){
        //printf("PP:%d\n",i);
        heapify(i,H);
    }
    return H;
}
void print_heap(typeheap aux){
    int i=0;
    for(i;aux.heap_size>=i;i++){
        printf("VV: %d\n", aux.A[i]);
    }
}
int main()
{
    typeheap heap;
    heap.heap_size=6;
    heap.A[0]=16;
    heap.A[1]=20;
    heap.A[2]=7;
    heap.A[3]=6;
    heap.A[4]=17;
    heap.A[5]=3;
    heap.A[6]=2;
    build_Max_heap(&heap);
    print_heap(heap);
    return 0;
}
