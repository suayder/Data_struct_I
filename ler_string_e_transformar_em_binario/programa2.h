typedef struct no{
    char info;
    struct no *prox;
}type_no;
typedef struct{
    type_no *last, *first;
}type_queue;

void start(type_queue *Q){
    Q->last=NULL;
    Q->first=NULL;
}
int insert_outset(type_queue *Q, char value){ //inserir no inicio
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
    newbox->prox=Q->first;
    Q->first=newbox;
    return 1;
}
int remove_outset(type_queue *Q, char *value){ //remover no inicio (e usado devido ao uso de uma pilnha para poder empilar os bits
    type_no *aux=Q->first;
    if(Q->first==NULL){
        printf("\nQueue underflow!");
        return 0;
    }
    if(Q->first->prox==NULL){
        *value=aux->info;
        free (aux);
        start(Q);
        return 1;
    }
    Q->first=Q->first->prox;
    *value=aux->info;
    aux->prox=NULL;
    free(aux);
    return 1;
}
void print_out(type_queue *Q){//imprimir string final
    type_no *aux=Q->first;
    printf("\n\nA string inicial é: ");
    while(aux!=NULL){
        printf("%c", aux->info);
        aux=aux->prox;
    }
    printf("\n\n");
}
void decode1(type_queue *Q, FILE **source){//A função que vai pegar a string do arquivo de texto, a qual estava escondendo os bits da outra e retirar os dois ultimos bits para poder ir montando a frase inicial
    char aux_d, host;
    int aux_cont=0;
    type_queue Q_aux;
    start(&Q_aux);
    while(fscanf((*source),"%c", &aux_d)!=EOF){
        aux_d=(aux_d&0b00000011);
        insert_outset(&Q_aux, aux_d);
    }
    while(Q_aux.first!=NULL){
        remove_outset(&Q_aux,&aux_d);
        host=(host|aux_d);
        //printf("%d\n", aux_d);
        if(aux_cont==3){
            //printf("%c\n", host);
            insert_outset(Q, host);
            aux_cont=-1;
        }
        host=host<<2;
        aux_cont++;
    }
}
void descrypting(){//essa é como se fosse a função principal do programa, é a que é chamada no arquivo 1
    FILE *source;
    type_queue Q;
    start(&Q);
    source=fopen("codigos.txt", "r");
    if(source==NULL){
        printf("Erro ao abrir o arquivo!\n");
    }
    decode1(&Q, &source);
    print_out(&Q);
    fclose(source);
}
