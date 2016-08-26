#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int value, degree;
    char var;
    struct no *prox, *ant;
}type_list;
type_list *list1=NULL, *list2=NULL;
int T_insert(type_list **T_list, int value, int degree, char var){
    type_list *newlist=(type_list*) malloc(sizeof(type_list));
    if(newlist==NULL){
        printf("\nlist overflow!");
        return 0;
    }
    newlist->value=value;
    newlist->degree=degree;
    newlist->var=var;
    newlist->ant=NULL;
    newlist->prox=NULL;
    if(*T_list==NULL){
        *T_list=newlist;
    }
    else{
        type_list *aux;
        for(aux=*T_list;aux->prox!=NULL;aux=aux->prox);
        aux->prox=newlist;
        newlist->ant=aux;
    }
    return 1;
}
int T_remove(type_list *T_list, int *value){
    printf("VV:%d\n", value);
    if(T_list==NULL){
        printf("\nlist underflow!");
        return 0;
    }
    else{
        type_list *aux=T_list;
        if(T_list->value==*value){
            T_list->prox->ant=NULL;
            T_list=T_list->prox;
            printf("MV1:%d\n", aux->value);
            free(aux);
            return 1;
        }
        while(aux->value!=value){
            aux=aux->prox;
            if(aux==NULL){
                printf("\nNot found!");
                return 0;
            }
            printf("A:%d\n", aux->ant->value);
            printf("P:%d\n", aux->prox->value);
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
        case '-': return 20;
        default: return -1;
    }
}
int organize_polynomial(type_list **p,char *str){
    int i, aux,value, degree;
    char var;
    for(i=0;str[i]!='\0';i++){
        value=0;
        degree=0;
        if((aux=chartoint(str[i]))==20) aux=chartoint(str[++i]);//se for negativo pula pra ser testado no final
        value=value+aux;
        aux=chartoint(str[++i]);
        while(aux!=-1&&str[i]!='\0'){//percorre o numero ate chegar em uma letra
            value=value*10+aux;
            aux=chartoint(str[++i]);
        }
        var=str[i]; //considerando que sempre haverá uma variável acompanhando o numero
        i+=2;
        aux=chartoint(str[i]);
        degree=aux;
        aux=chartoint(str[++i]);
        while(str[i]!='+'&&str[i]!='-'&&str[i]!='\0'){//buscar o grau do polinômio
            degree=degree*10+aux;
            aux=chartoint(str[++i]);
        }
        if(str[i]=='-') value=value*(-1);
        T_insert(p,value,degree,var);
    }
    return 1;
}
void print_out(type_list **p){//imprimir string final
    type_list *aux=*p;
    while(aux!=NULL){
        printf("\nvalue %d", aux->value);
        printf("\ndegree %d", aux->degree);
        aux=aux->prox;
    }
    printf("\n\n");
}
int main(){
    char pol1[20], pol2[20];
    printf("polinomios:\n");
    //scanf("%s", pol1);
    scanf("%s", pol2);
    //organize_polynomial(&list1, pol1);
    organize_polynomial(&list2, pol2);
    print_out(&list2);
    return 0;
}
