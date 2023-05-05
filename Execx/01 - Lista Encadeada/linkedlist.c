#include <stdio.h>
#include <stdlib.h>

//LISTA ENCADEADA

typedef struct dados {
  int num;
  struct dados *prox;
} Dados;

Dados* criar_dado() {
  Dados *novo = (Dados*)malloc(sizeof(Dados));
  return novo;
}

Dados *inserir_dados_inicio(Dados *Lista, int dado) {
  Dados *novo_dado = criar_dado();
  novo_dado->num = dado;

  if(Lista == NULL) {
    Lista = novo_dado;
    novo_dado->prox = NULL; // a lista recebe o novo dado e ela aponta p/ o
                            // proximo valor que é NULL
  }else {
    novo_dado->prox =
        Lista; // o dado vai apontar pra onde a lista estava apontando
    Lista = novo_dado;
  }
  return Lista;
}

void imprimir_dados(Dados *Lista) {
  Dados *aux = Lista;

  while (aux != NULL) {
    printf("%d ", aux->num);
    aux = aux->prox;
  }
}

int main() {
  Dados *Lista = NULL; // ponteiro que aponta para um elemento do mesmo tipo

  Lista = inserir_dados_inicio(Lista, 20);
  Lista = inserir_dados_inicio(Lista, 30);
  Lista = inserir_dados_inicio(Lista, 40);
  Lista = inserir_dados_inicio(Lista, 50);
  Lista = inserir_dados_inicio(Lista, 60);
  Lista = inserir_dados_inicio(Lista, 70);
  Lista = inserir_dados_inicio(Lista, 80);
  imprimir_dados(Lista);

  return 0;
}