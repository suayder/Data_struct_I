/*OBS: A função system, da linha 31 esta inderexada para abrir o primeiro programa, porem, o endereço que esta nela
e o endereço do meu computador, eu não descobri outra forma de fazer isso por isso pode ser que dê algum problema na hora de executar*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct type{
    char *piece_word;
    struct type *prox;
}box;
typedef struct{
    box *front;
    box *rear;
}type_queue;
type_queue *queue;
box **list;
int size_list;
int search_word(char *word, int index);
int binary_search(char *word);
int insert_queue(char *word, int index);
void start_queue();
int insert(char *word, int index, int i);
int remove_list(char *word, int i);
void imprime();

int main(){
    FILE *arq_index;
    FILE *arq_searh;
    char *aux;
    int index;
    system("/home/suayder/Desktop/ESTRUTURA_DE_DADOS/smcosta-trablR/Programa_secundario/bin/Debug/Programa_secundario");
    arq_index=fopen("index_words.txt", "r");
    arq_searh=fopen("search_string.txt", "r");
    if(!arq_index || !arq_searh){
        printf("\nerror in file opening\n");
        exit(1);
    }
    else{
        fscanf(arq_index, "%d", &index);
        fscanf(arq_index, "%d", &size_list);
        aux=(char*) malloc(index*sizeof(char));
        list=(box*) malloc(size_list*sizeof(box));
        int i=0;
        while(fscanf(arq_index, "%s", aux)!=EOF){
            insert(aux, index, i);
            i++;
        }
        aux=(char*) malloc(15*sizeof(char));
        while(fscanf(arq_searh, "%s", aux)!=EOF){
            search_word(aux, index);
        }
        start_queue();
        for(i=0;i<size_list;i++){
            remove_list(aux,i);
            while(list[i]!=NULL){
                remove_list(aux,i);
                insert_queue(aux, strlen(aux));
            }
        }
        imprime();
     }
    fclose(arq_searh);
    fclose(arq_index);
    return 0;
}
int search_word(char *word, int size_word){
    int i=0, pos;
    char *word_aux=(char*)malloc(size_word*sizeof(char));
    while(word[i+size_word-1]!='\0'){
        int j=0;
        while(j<size_word){
            word_aux[j]=word[i+j];
            j++;
        }
        pos=binary_search(word_aux);
        if(pos!=-1){
            insert(word,strlen(word),pos);
        }
        i++;
    }
}
int binary_search(char *word){
    int first=0, last=size_list-1, middle;
    while(first<=last){
        middle=(int)((first+last)/2);
        if(strcmp(list[middle]->piece_word,word)==0){
            return middle;
        }
        else if(strcmp(list[middle]->piece_word,word)<0){
            first=middle+1;
        }
        else{
            last=middle-1;
        }
    }
    return -1;
}
int insert_queue(char *word, int index){
    box *newqueue=(box*) malloc(sizeof(box));
    if(newqueue==NULL){
        printf("list overflow");
        return 1;
    }
    newqueue->piece_word=(char*) malloc((index)*sizeof(char));
    if(newqueue->piece_word==NULL){
        printf("Alloc error");
        return 1;
    }
    strcpy(newqueue->piece_word,word);
    if(queue->front==NULL){
        queue->front=newqueue;
        queue->rear=newqueue;
    }
    else if((strcmp(word,queue->front->piece_word)<0)){
        newqueue->prox=queue->front;
        queue->front=newqueue;
    }
    else if((strcmp(word,queue->rear->piece_word)>0)){
        queue->rear->prox=newqueue;
        queue->rear=newqueue;
    }
    else{
        box *aux=queue->front;
        while(aux!=NULL && strcmp(word,aux->piece_word)>0){
            aux=aux->prox;
            if(strcmp(word,aux->prox->piece_word)<=0) break;
        }
        if(strcmp(aux->piece_word,word)==0) return 0;
        newqueue->prox=aux->prox;
        aux->prox=newqueue;
    }
    return 0;
}
int insert(char *word, int index, int i){
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
    if(list[i]==NULL){
        newlist->prox=list[i];
        list[i]=newlist;
        return 0;
    }
    newlist->prox=list[i]->prox;
    list[i]->prox=newlist;
    return  0;
}
int remove_list(char *word, int i){
    strcpy(word,list[i]->piece_word);
    box *aux=list[i];
    list[i]=list[i]->prox;
    aux->prox=NULL;
    free(aux);
    return 0;
}
void imprime(){
    box *aux;
    aux=queue->front;
    printf("Resulting words:\n");
    while(aux!=NULL){
        printf("\n%s\n", aux->piece_word);
        aux=aux->prox;
    }
}
void start_queue(){
    queue=(type_queue*)malloc(sizeof(type_queue));
    queue->front=NULL;
    queue->rear=NULL;
}
