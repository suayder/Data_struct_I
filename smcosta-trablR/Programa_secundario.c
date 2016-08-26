#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct type{
    char *piece_word;
    struct type *prox;
}box;
box *list=NULL, *list2=NULL;
int size_list=0;

int insert(char *word, int index);
int remove_list(char *word);
void imprime();
int lexcographical_organization();

int main(){
    FILE *arq;
    char word[20];
    int index;
    arq=fopen("index_words.txt", "w");
    if(!arq){
        printf("\nerror in file opening\n");
        exit(1);
    }
    else{
       printf("type the word:");
       scanf("%s", word);
       int a;
       for(a=0;a<strlen(word);a++){
        word[a]=toupper(word[a]);
       }
       printf("index:");
       scanf("%d", &index);
       char *aux=(char*)malloc(index*sizeof(char));
       if(index>=strlen(word)){
            insert(word, strlen(word));
        }
       else{
            int i=0;
            while(word[i+index-1]!='\0'){
                int j=0;
                while(j<index){
                    aux[j]=word[i+j];
                    j++;
                }
                insert(aux, index);
                i++;
            }
       }
       while(list!=NULL){//bloco para organizar a lista lexcograficamente
            remove_list(aux);
            lexcographical_organization(aux, index);
      }
      fprintf(arq,"%d\n",index);
      fprintf(arq,"%d\n",size_list);
       while(list2!=NULL){
        fprintf(arq,"%s\n",list2->piece_word);
        list2=list2->prox;
      }
    }
    fclose(arq);
    return 0;
}
int insert(char *word, int index){
    box *newlist;
    newlist=(box*) malloc(sizeof(box));
    if(newlist==NULL){
        printf("Alloc error");
        exit(1);
    }
    newlist->piece_word=(char*) malloc((index)*sizeof(char));
    if(newlist->piece_word==NULL){
        printf("Alloc error");
        return 1;
    }
    strcpy(newlist->piece_word,word);
    newlist->prox=list;
    list=newlist;
    //printf("\n%s\n", list->piece_word);
    return  0;
}
int remove_list(char *word){
    if(list==NULL){
        printf("list underflow");
        return 1;
    }
    strcpy(word,list->piece_word);
    box *aux=list;
    list=list->prox;
    aux->prox=NULL;
    free(aux);
    return 0;
}
void imprime(){
    box *aux=list2;
    while(aux!=NULL){
        printf("\n%s\n", aux->piece_word);
        aux=aux->prox;
    }
}
int lexcographical_organization(char *word, int index){
    box *newlist=(box*) malloc(sizeof(box));
    if(newlist==NULL){
        printf("list overflow");
        return 1;
    }
    newlist->piece_word=(char*) malloc((index)*sizeof(char));
    if(newlist->piece_word==NULL){
        printf("Alloc error");
        return 1;
    }
    strcpy(newlist->piece_word,word);

    if(list2==NULL || (strcmp(word,list2->piece_word)<=0)){
        newlist->prox=list2;
        list2=newlist;
        size_list++;
    }

    else{
        box *aux=list2;
        while(aux->prox!=NULL && strcmp(word,aux->piece_word)>0){
            if(strcmp(word,aux->prox->piece_word)<=0) break;
            aux=aux->prox;
        }
        newlist->prox=aux->prox;
        aux->prox=newlist;
        size_list++;
    }
    return 0;
}
