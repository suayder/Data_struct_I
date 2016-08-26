//josef
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct no{
    char info[15];
    struct no *prox, *ant;
};
int insert_inicio(struct no **list,char **info){
    struct no *newbox=(struct no*) malloc(sizeof(struct no));
    if(newbox==NULL){
        printf("\nQueue overflow!");
        return 0;
    }
    strcpy(newbox->info,*info);
    if(*list==NULL){
        (*list)=newbox;
        (*list)->prox=*list;
        (*list)->ant=*list;
    }
    else{
        newbox->prox=(*list);
        newbox->ant=(*list)->ant;
        (*list)->ant=newbox;
        newbox->ant->prox=newbox;
        *list=newbox;
    }
    return 1;
}
int remove_begin(struct no **list, char *info){
    if(*list==NULL){
        printf("\nlist underflow!");
        return 0;
    }
    struct no *aux=*list;

    if(strcmp(info,(*list)->info)==0){
        if((*list)->prox==*list){
           // free(*list);
           // *list=NULL;
            return 1;
        }
        (*list)->prox->ant=(*list)->ant;
        (*list)->ant->prox=(*list)->prox;
        *list=aux->prox;
        aux->prox=NULL;
        aux->ant=NULL;
        free(aux);
        return 1;
    }
    while(aux->info!=info){
        aux=aux->ant;
        if(aux==*list) return 0;
    }
        aux->prox->ant=aux->ant;
        aux->ant->prox=aux->prox;
        aux->ant=NULL;
        aux->prox=NULL;
        free(aux);
        return 1;
}
void print_list(struct no **list){
    struct no *aux=*list;
    do{
        printf("\nJosephos tem que ficar na posição de %s para se salvar\n", aux->info);
        aux=aux->prox;
    }while(aux!=*list);
}
int sorteio(){
    return (rand()%21);
}
int select_soldier(struct no **list, int n){
    struct no *aux=*list;
    int cont;
    char *name;
    printf("\nnomes sequenciados dos que sairam:\n\n");
    while((*list)->prox!=*list){
        for(cont=0;cont<n;cont++) aux=aux->prox;
        name=aux->info;
        *list=aux->prox;
        printf("%s\n", name);
        remove_begin(&aux, name);

        aux=*list;
    }
    return 1;
}
int main()
{
    FILE *arq_names;
    struct no *list=NULL;
    char *nome;
    srand(time(NULL));
    arq_names=fopen("nomes.txt", "r");
    if(arq_names==NULL){
        printf("erro  na leitura do arquivo");
        return 0;
    }
    while(fscanf(arq_names, "%s", nome)!=EOF){
        insert_inicio(&list, &nome);
    }
    int i=sorteio(), n;
    while(i>0){
        list=list->prox;
        i--;
    }
    printf("O numero n: ");
    scanf("%d", &n);
    select_soldier(&list, n);
    print_list(&list);
    fclose(arq_names);
    return 0;
}
