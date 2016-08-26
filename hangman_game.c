#include <stdio.h>
#include <stdlib.h>//e necessaria para utilizar a função rand
#include <time.h> //para poder usar srand(time(NULL))
#include <string.h>

int sorteio(int *x){

    srand(time(NULL));
    *x= rand() %20;
    return *x;

}


int main(){
    char r;

    do{
        FILE *arq;

        char str[12],*palavra, *letra;
        int i, x, j, k, aux;

        arq=fopen("unidades_de_medidas.txt", "r");

        if(arq!=NULL){

            sorteio(&x);
            i=0;
            while(fgets(str,12,arq) != NULL){
                if(i==x){
                    break;
                }
                i++;

            }



            i = strlen(str)-1;
            palavra=calloc(i, sizeof (char*));
            letra=calloc(i, sizeof (char*));
            str[i]='\0';

            for(j=0;j<i;j++) palavra[j]='_';


            for(j=0;j<3;j++){

                while(1){
                    system("clear");
                    printf("%s\n", str);
                    printf("-----------------JOGO DA FORCA----------------\n\n\nA DICA E: UNIDADES DE MEDIDAS\n");
                    printf("REGRAS:\n1 - desconsidere letras maiusculas e acentos\n2 - Voce nao pode digitar mais de uma letra, exceto se for a palavra inteira!\n\n");

                    aux=0;
                    printf("\n\nATENCAO!  Voce tem %d chances!\n\n",(10-j));
                    printf("PALAVRA: %s \n\n", palavra);

                    printf("digite a letra: ");
                    scanf("%s", letra);


                    if(strcmp(letra,str)==0){
                        printf("-------------------\nPALAVRA: %s\n\nVoce acertou!\n-----------------\n",letra);
                        setbuf(stdin,NULL);
                        //getchar();//OBS: todos tem dois getchar porque um ficou para armazenar um buffer
                        getchar();
                        goto A;
                    }
                    else{


                        for(k=0;k<i;k++){

                            if(letra[1]!='\0'){
                                setbuf(stdin, NULL);
                                break;

                                }
                            if(letra[0]==str[k]){
                                palavra[k]=str[k];
                                aux=1;

                            }
                        }
                        if(aux==0) break;
                        if(strcmp(palavra,str)==0){
                            printf("-------------------\nPALAVRA: %s\n\nVoce acertou!\n-----------------",palavra);
                            getchar();
                            getchar();
                            goto A;
                        }

                    }


                }


            }
            printf("-------------------\nPALAVRA: %s\n\nVoce perdeu!\n-----------------\n",str);
            setbuf(stdin, NULL);
            getchar();

        }


        else printf("O ARQUIVO NAO ABRIU!");

        fclose(arq);

    A:system("clear");
    printf("---------------JOGO DA FORCA----------------\n\n\n");
    printf("\n\nDIGITE:\nS - JOGAR NOVAMENTE\n\nQUALQUER TECLA PARA SAIR\n\n: ");
    scanf("%c", &r);
    system("clear");

    }while(r=='s' || r=='S');
    return 0;

}
