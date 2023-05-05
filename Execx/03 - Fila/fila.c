#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_na_fila(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No)); //alocar memória para novo no
    if(novo){
        novo -> valor = num;
        novo ->proximo = NULL;
        if(*fila == NULL){
            *fila = novo; //opcao para quando o ponteiro apontar para vazio, no caso apenas para a primeira vez
        }else{
            aux = *fila;
            while(aux -> proximo){
                aux = aux ->proximo;
            }
            aux->proximo = novo;
        }
    }else{
        printf("\n Erro na alocação de memória");
    }
}
//essa função retorna um ponteiro para um nó
No* remover_da_fila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover ->proximo;
    }else{
        printf("\n Fila vazia chefe!");
    }
    return remover;
}

void imprimir_fila(No *fila){
    printf("\t=======FILA======\n\t");
    while(fila){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t=======FILA======\n");
}

int main(){
    No *r, *fila = NULL;

    int option, valor;

    do{
      printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
      scanf("%d", &option);

      switch(option){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_na_fila(&fila, valor);
                break;
        case 2:
            r = remover_da_fila(&fila);
            if(r){
                printf("Removido: %d\n", r->valor);
                free(r);
            }
                break;
        case 3:
            imprimir_fila(fila);
                break;
        default:
            if(option != 0){
                printf("\nOpcao Invalida");
            }
      }
    } while (option != 0);
    
}