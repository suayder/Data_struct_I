#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int n;
}item;
typedef struct{
    item num[MAX];
    int pfim;//posição fim
}lista;
typedef struct{
    int n2;
}item2;
typedef struct{
    item2 num2[MAX];
    int pfim2;
}lista2;
typedef struct{
    int n3;
}item3;
typedef struct{
    item3 num3[MAX*2];
    int pfim3;
}lista3;
void iniciar(lista *V, lista2 *V2, lista3 *V3){
   int i;
   V->pfim=0;
   V2->pfim2=0;
   V3->pfim3=0;
   for(i=0;i<MAX;i++){
        V->num[i].n=NULL;
        V2->num2[i].n2=NULL;
   }
}
int listavazia(lista *V){
        if (V==NULL) return -1;
        return V->pfim ==0;
}
int listacheia(lista *V){
    if(V==NULL) return -1;
    return V->pfim>=(MAX);
}
void inserir(lista *V){
    item valor;
    printf("valor: ");
    scanf("%d", &valor);
    V->num[V->pfim]=valor;
    V->pfim++;
}
void inserirposicao(lista *V){
    int i, pos;
    item valor;
    printf("posicao:");
    scanf("%d",&pos);
    if(V->num[pos-1].n==NULL)inserir(V);
    else{
        printf("valor:");
        scanf("%d", &valor);
        for(i=V->pfim;i>=pos;i--){
            V->num[i].n=V->num[i-1].n;
        }
        V->num[pos-1].n=valor.n;
        V->pfim++;
    }
}
void imprime(lista *V){
    int i;
    for(i=0;i<V->pfim;i++){
        printf("N: %d\n", V->num[i].n);
    }
}
void remover(lista *V, item *valor){
    int i=0, j;
    while(i<V->pfim && V->num[i].n!=(*valor).n) i++;
    if(i!=V->pfim){
        for(j=i;j<V->pfim;j++) V->num[j].n=V->num[j+1].n;
        V->pfim--;
    }
    else printf("numero nao encontrado\n");
}
void ordem(lista *V){
    int i=0, j=0, a=0;
    while((V->num[a].n)==(V->num[a+1].n)) a++;
    while((V->num[i].n)>=(V->num[i+1].n) && i<V->pfim) i++;
    while((V->num[j].n)<=(V->num[j+1].n) && j<V->pfim) j++;
    if(i==((V->pfim)) && j-a==0) printf("lista decrescente\n");
    else if(i-a==0 && j==((V->pfim)-1)) printf("lista crescente\n");
    else printf("lista nao e ordenada\n");
}
void copia(lista *V, lista2 *V2){
    int i;
    for(i=0;i<V->pfim;i++){
        V2->num2[i].n2=V->num[i].n;
    }
    V2->pfim2=V->pfim;
}
void imprime_L2(lista2 *V2){
    int i;
    for(i=0;i<V2->pfim2;i++){
        printf("N2: %d\n", V2->num2[i].n2);
    }
}
void tirar_repetidos(lista2 *V2){
    int i=0, j, k;
    while(i<V2->pfim2){
        j=i+1;
        while(j<V2->pfim2){
            if(V2->num2[i].n2==V2->num2[j].n2){
                for(k=j;k<V2->pfim2;k++){
                    V2->num2[k].n2=V2->num2[k+1].n2;
                }
                V2->pfim2--;
            }
            j++;
        }
        i++;
    }
}
void copiar_invertido(lista *V, lista2 *V2){
    int i;
    for(i=(V->pfim-1);i>=0;i--){
        V2->num2[(V->pfim-1)-i].n2=V->num[i].n;
    }
    V2->pfim2=V->pfim;
}
void inverterL1(lista *V, lista *V1){
    int i;
    for(i=0;i<V->pfim;i++){
        V1->num[i].n=V->num[V->pfim-(i+1)].n;
        printf("VVV: %d\n", V1->num[i].n);
    }
    for(i=0;i<V->pfim;i++){
        V->num[i].n=V1->num[i].n;
    }
}
void intercalar(lista *V, lista2 *V2, lista3 *V3){
    int i=0, k=0;
    V3->pfim3=V->pfim+V2->pfim2;
    if(V->pfim>=V2->pfim2){
        while(k<V3->pfim3){
            if(k%2==0){
                V3->num3[k].n3=V->num[i].n;
            }
            else{
                V3->num3[k].n3=V2->num2[i].n2;
                i++;
            }
            k++;
        }
    }
    else{
        while(k<V3->pfim3){
            if(k%2==0){
                V3->num3[k].n3=V2->num2[i].n2;
            }
            else{
                V3->num3[k].n3=V->num[i].n;
                i++;
            }
            k++;
        }
    }
}
void imprimeL3(lista3 *V3){
    int i;
    for(i=0;i<V3->pfim3;i++){
        printf("N3: %d\n", V3->num3[i].n3);
    }
}
void eliminar_elemento(lista *V){
    int i=0, j;
    item elemento;
    printf("Elemento:");
    scanf("%d", &elemento);
    while(i<V->pfim){
        if(elemento.n==V->num[i].n){
            for(j=i;j<V->pfim;j++) V->num[j].n=V->num[j+1].n;
            i--;
            V->pfim--;
        }
        i++;
    }
}
int main(){
    lista v, v1;
    lista2 v2;
    lista3 v3;
    int aux;
    item valor;
    iniciar(&v, &v2, &v3);
    do{
        printf("0- SAIR\n1- INSERIR\n2- REMOVER UM ITEM\n3- IMPRIMIR L1\n4- IMPRIMIR L2\n5- IMPRIMIR L3\n6- ORDEM DE L1\n7- COPIA PARA L2\n8- COPIAR SEM REPETIDOS PARA L2\n9- COPIAR RESULTADO INVERTIDO PARA L2\n10- INVERTER L1\n11- INTERCALAR PARA L3\n12- ELIMINAR OCORRENCIA DE ELEMENTO EM L1\n:");
        scanf("%d", &aux);
        switch(aux){
            case 1:
                if(listacheia(&v)) printf("lista cheia!\n");
                else if(v.pfim==0) inserir(&v);
                else inserirposicao(&v);
                break;
            case 2:
                if(listavazia(&v)) printf("\nlista vazia, nao e possivel remover!\n\n");
                else{
                    printf("digite o valor: ");
                    scanf("%d", &valor);
                    remover(&v, &valor);
                }
                break;
            case 3:
                imprime(&v);
                break;
            case 4:
                imprime_L2(&v2);
                break;
            case 5:
                imprimeL3(&v3);
                break;
            case 6:
                if(listavazia(&v)) printf("lista vazia!\n");
                else ordem(&v);
                break;
            case 7:
                if(listavazia(&v)) printf("lista vazia!\n");
                else copia(&v, &v2);
                break;
            case 8:
                if(listavazia(&v)) printf("lista vazia!\n");
                else{
                    copia(&v, &v2);
                    tirar_repetidos(&v2);
                }
                break;
            case 9:

                if(listavazia(&v)) printf("lista vazia!\n");
                else copiar_invertido(&v, &v2);
                break;
            case 10:
                if(listavazia(&v)) printf("lista vazia!\n");
                else inverterL1(&v, &v1);
                break;
            case 11:
                if(listavazia(&v)) printf("lista vazia!\n");
                else intercalar(&v, &v2, &v3);
                break;
            case 12:
                eliminar_elemento(&v);
                break;
        }
    }while(aux!=0);
    return 0;
}
