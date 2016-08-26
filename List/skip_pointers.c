#include <stdio.h>
#include <stdlib.h>
struct no{
    int info;
    struct no *prox, *ant,*skip;
};
int size_list;
int inserirNaLista(int newInfo, struct no** lista){
	struct no* novo = (struct no*)malloc(sizeof(struct no));
	if(novo == NULL){printf("Erro de memoria...\n"); return;}
	novo->ant = novo;
	novo->prox = novo;
	novo->info = newInfo;
	if((*lista) == NULL){
		*lista = novo;
		size_list++;
		return 1;
	}
	(*lista)->ant->prox = novo;
	novo->ant = (*lista)->ant;
	(*lista)->ant = novo;
	novo->prox = (*lista);
	size_list++;
    return 1;
}
void imprimirLista(struct no** lista){
	struct no *aux;
	if(*lista == NULL){ printf("Lista vazia...\n"); return 0;}
	for(aux = (*lista); aux->prox != (*lista); aux = aux->prox){
		printf("%d->", aux->info);
	}printf("%d\n", aux->info);
}
void set_skip(struct no **L, int n){
    int cont=0;
    struct no *aux=*L, *aux_skip=*L;
    while(aux!=NULL){
        aux->skip=NULL;
        if(cont==n){
            aux_skip=aux;
            cont=0;
            aux_skip=aux;
        }
        aux=aux->prox;
        cont++;
    }
}
void imprimirskip(struct no** lista){
	struct no *aux;
	if(*lista == NULL){ printf("Lista vazia...\n"); return 0;}
	while(aux!=NULL){

		printf("%d->", aux->skip);
	}printf("%d\n", aux->skip);
}
int main()
{
    size_list=0;
    struct no *lista=NULL, *lista2;
    int i;
    for (i=1;i<10;i++) inserirNaLista(i, &lista);
    for (i=0;i<14;i+=2) inserirNaLista(i, &lista2);
    imprimirLista(&lista);
    imprimirLista(&lista2);
    return 0;
}
