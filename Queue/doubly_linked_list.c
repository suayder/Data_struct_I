#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int data;
    struct no *prox, *ant;
}type_list;
type_list *T_list=NULL;
int T_insert(int value){
    type_list *newlist=(type_list*) malloc(sizeof(type_list));
    if(newlist==NULL){
        printf("\nlist overflow!");
        return 0;
    }
    newlist->data=value;
    newlist->ant=NULL;
    newlist->prox=NULL;
    if(T_list==NULL){
        T_list=newlist;
    }
    else{
        type_list *aux;
        for(aux=T_list;aux->prox!=NULL;aux=aux->prox);
        aux->prox=newlist;
        newlist->ant=aux;
    }
    return 1;
}
int T_remove(int value){
    printf("VV:%d\n", value);
    if(T_list==NULL){
        printf("\nlist underflow!");
        return 0;
    }
    else{
        type_list *aux=T_list;
        if(T_list->data==value){
            T_list->prox->ant=NULL;
            T_list=T_list->prox;
            printf("MV1:%d\n", aux->data);
            free(aux);
            return 1;
        }
        while(aux->data!=value){
            aux=aux->prox;
            if(aux==NULL){
                printf("\nNot found!");
                return 0;
            }
            printf("A:%d\n", aux->ant->data);
            printf("P:%d\n", aux->prox->data);
        }

        if(aux->prox==NULL){
            aux->ant->prox=NULL;
            free(aux);
            return 1;
        }
        aux->ant->prox=aux->prox;
        aux->prox->ant=aux->ant;
        free(aux);
        return 1;
    }
}
int insert_orderly(int value){
    type_list *newlist=(type_list*) malloc(sizeof(type_list));
    if(newlist==NULL){
        printf("\nlist overflow!");
        return 0;
    }
    newlist->data=value;
    newlist->ant=NULL;
    newlist->prox=NULL;
    if(T_list==NULL){
        T_list=newlist;
        return 1;
    }
    else{
        if(value<=T_list->data){
            newlist->prox=T_list;
            T_list->ant=newlist;
            T_list=newlist;
            return 1;
        }
        type_list *aux=T_list;
        while(value>aux->data){
            aux=aux->prox;
            if(aux->prox==NULL && value>=aux->data){
                newlist->ant=aux;
                aux->prox=newlist;
                return 1;
            }
        }
        newlist->ant=aux->ant;
        newlist->prox=aux;
        aux->ant->prox=newlist;
        return 1;
    }
}
void print_out(){
    type_list *aux=T_list;
    while(aux!=NULL){
        printf("\nINFO: %d", aux->data);
        aux=aux->prox;
    }
}
int main(){
    int i[]={10,6,2,9,2,5,0,1}, j;
    for(j=0;j<8;j++)insert_orderly(i[j]);
    //T_remove(0);
    printf("%d",T_remove(5));
    //print_out();
    //T_remove(2);
    print_out();
    return 0;
}
