#include <stdio.h>
#include <stdlib.h>

struct no{
    int info;
    struct no *prox, *ant;
};
typedef struct{
    struct no *inicio, *fim;
    int size_Q;
}type_queue;
type_queue Q1, Q2, Q3, Q4, Q5;
void start (type_queue *Q){
    Q->inicio=NULL;
    Q->fim=NULL;
    Q->size_Q=0;
}
void print_queue(type_queue *Q){
    struct no *aux=Q->inicio;
    while(aux->info==0){
        aux=aux->prox;
        if(aux==NULL){
            printf("0");
            break;
        }
    }
    while(aux!=NULL){
        printf("%d", aux->info);
        aux=aux->prox;
    }
}
int insert_inicio(type_queue *Q, int value){
    struct no *newbox=(struct no*) malloc(sizeof(struct no));
    if(newbox==NULL){
        printf("\nQueue overflow!");
        return 0;
    }
    newbox->info=value;
    newbox->ant=NULL;
    newbox->prox=NULL;
    if(Q->inicio==NULL){
        Q->inicio=newbox;
        Q->fim=newbox;
    }
    else{
        Q->inicio->ant=newbox;
        newbox->prox=Q->inicio;
        Q->inicio=newbox;
    }
    Q->size_Q++;
    return 1;
}
int remove_fim(type_queue *Q, int *value){
    if(Q->inicio==NULL){
        printf("\nQueue underflow!");
        return 0;
    }
    if(Q->inicio->prox==NULL){
        free(Q);
        start(Q);
        return 1;
    }
    struct no *aux=Q->fim;
    Q->fim=Q->fim->ant;
    *value=aux->info;
    aux->ant=NULL;
    Q->fim->prox=NULL;
    free(aux);
    Q->size_Q--;
    return 1;
}
int chartoint(char c){
    switch(c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
    }
}
int aux_sum(struct no *Q, struct no *R, int *value, int sobe){
    *value=Q->info+R->info+sobe;
    if(*value>9){
        *value=*value-10;
        return 1;
    }
    else{
        return 0;
    }

}
void sum(type_queue *Q, type_queue *R, type_queue *I){
    int i=0, value;
    struct no *aux1=Q->inicio, *aux2=R->inicio;
    while(aux1!=NULL || aux2!=NULL){
        if(Q->size_Q==R->size_Q){
            i=aux_sum(aux1, aux2,&value,i);
            insert_inicio(I, value);
            aux1=aux1->prox;
            aux2=aux2->prox;
        }
        else{
            if(aux1==NULL){
                if(i==1){
                    aux2->info++;
                    if(aux2->info<10) i=0;
                }
                insert_inicio(I,aux2->info);
                aux2=aux2->prox;
            }
            else if(aux2==NULL){
                if(i==1){
                    aux1->info++;
                    if(aux1->info<10) i=0;
                }

                insert_inicio(I, aux1->info);
                aux1=aux1->prox;
            }
            else{
                i=aux_sum(aux1,aux2,&value,i);
                insert_inicio(I,value);
                aux1=aux1->prox;
                aux2=aux2->prox;
            }
        }
    }
    if(i==1)
        insert_inicio(&Q3, 1);
}
int aux_sub(struct no *Q, struct no *R, int *value){
    *value=Q->info-R->info;
    if(*value<0){
        Q->info+=10;
        *value=Q->info-R->info;
        if(Q->prox==NULL) return -1;
        Q->prox->info--;
        return -1;
    }
    else{
        return 0;
    }
}
void sub(){
    int i=0, value;
    struct no *aux1=Q1.fim, *aux2=Q2.fim;
    while(aux1->info>=aux2->info){
        aux1=aux1->ant;
        aux2=aux2->ant;
        if(aux1==NULL || aux2==NULL) break;
    }
    if((aux1==NULL && aux2==NULL)||(Q1.size_Q>Q2.size_Q)){
        aux1=Q1.inicio;
        aux2=Q2.inicio;
    }
    else if((aux1!=NULL)||(Q1.size_Q<Q2.size_Q)){
        aux1=Q2.inicio;
        aux2=Q1.inicio;
        printf("-");
    }
    else{
        aux1=Q1.inicio;
        aux2=Q2.inicio;
    }
    while(aux1!=NULL || aux2!=NULL){
        if(Q1.size_Q==Q2.size_Q){
            i=aux_sub(aux1, aux2,&value);
            insert_inicio(&Q4, value);
            aux1=aux1->prox;
            aux2=aux2->prox;
        }
        else{
            if(aux1==NULL){
                insert_inicio(&Q4,aux2->info);
                aux2=aux2->prox;
                i=0;
            }
            else if(aux2==NULL){
                insert_inicio(&Q4, aux1->info);
                aux1=aux1->prox;
                i=0;
            }
            else{
                i=aux_sub(aux1, aux2,&value);
                insert_inicio(&Q4, value);
                aux1=aux1->prox;
                aux2=aux2->prox;
            }
        }
    }
}
int mult(struct no *Q, struct no *R, type_queue *aux_Q5, int *value, int sobe){
    if(R==NULL){
        insert_inicio(aux_Q5, sobe);
        return 0;
    }
    *value=(Q->info)*(R->info)+sobe;
    if(*value>9){
        sobe=*value/10;
        *value=*value%10;
    }
    insert_inicio(aux_Q5, (*value));
    R=R->prox;
    return (mult(Q, R,aux_Q5,value,sobe));
}
int main(){
    int i;
    start(&Q1);
    start(&Q2);
    start(&Q3);
    start(&Q4);
    start(&Q5);
    char num1[100], num2[100];
    printf("valor 1:");
    scanf("%s", num1);
    printf("valor 2:");
    scanf("%s", num2);
    puts("OBS: a multiplicacao ta funcionando somente para numeros em que o primeiro contenha so um dígito, ex: aXabcd...");
    i=0;
    while(num1[i]!='\0'){
        insert_inicio(&Q1,chartoint(num1[i]));
        i++;
    }
    i=0;
    while(num2[i]!='\0'){
        insert_inicio(&Q2,chartoint(num2[i]));
        i++;
    }
    i=0;
    sum(&Q1,&Q2,&Q3);
    printf("\nSoma:");
    print_queue(&Q3);
    printf("\nSubtracao:");
    sub();
    print_queue(&Q4);
    printf("\nmultiplicacao:");
    mult(Q1.inicio,Q2.inicio, &Q5, &i,0);
    print_queue(&Q5);
    return 0;
}
