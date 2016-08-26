#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "programa2.h"

int insert_fim(type_queue *Q, char value){//somente o inserir no fim,  o remover se encontra no arquivo .h
    type_no *newbox=(type_no*) malloc(sizeof(type_no));
    if(newbox==NULL){
        printf("\nQueue overflow!");
        return 0;
    }
    newbox->info=value;
    newbox->prox=NULL;
    if(Q->first==NULL){
        Q->first=newbox;
        Q->last=newbox;
        return 1;
    }
    Q->last->prox=newbox;
    Q->last=newbox;
    return 1;
}
void decode(char aux_d, type_queue *Q){//esta é para separar os bits que eu quero esconder
    int cont;
    char host;
    for(cont=0;cont<4;cont++){
            host=(aux_d&0b00000011);
            insert_fim(Q, host);
            aux_d=aux_d>>2;
        }
}
void code(FILE **arq, char aux_c, char str){//esta para colocar na string 2 a qual esconderá os bits que eu quero guardar
    char host;
    host=(aux_c|(str&0b11111100));
    //insert_fim(Q, host);
    fprintf(*arq, "%c", host);
}
int main(){

    char str[10], str2[200], host;
    int i, cont=0;
    type_queue Q, Q2;
    FILE *sourse_file;
    sourse_file=fopen("codigos.txt", "w");
    if(sourse_file==NULL){
        printf("Erro ao abrir o arquivo");
        return 0;
    }

    start(&Q);
    start(&Q2);

    printf("string 1:\n");
    scanf("%[^\n]s", str);
    setbuf(stdin, NULL);
    printf("string 2:\n");
    scanf("%[^\n]s", str2);
    setbuf(stdin, NULL);

    for(i=0;i<strlen(str);i++){
        decode(str[i], &Q);
    }
    while(Q.first!=NULL){
        remove_outset(&Q, &host);
        code(&sourse_file, host, str2[cont]);
        cont++;
    }
    fclose(sourse_file);
    descrypting();
    return 0;
}
