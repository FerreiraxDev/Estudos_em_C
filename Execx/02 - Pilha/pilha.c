#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAXTAM 7 //define o numero máximo


typedef struct{
    int vetor[MAXTAM];
    int topo;
}Pilha;

void empilhar(int valor, Pilha *pilha){
    //condição para que a pilha possa empilhar ainda, se n estiver cheia
    if(pilha->topo < MAXTAM){
        pilha->vetor[pilha->topo] = valor;
        pilha->topo++;
    }else{
        printf("Pilha está cheia! \n");
    }   
}

void desempilhar(Pilha *pilha){
    //testar se a pilha não está vazia
    if(pilha->topo > 0){
        pilha->topo--;
        printf("Elemento retirado: %d\n", pilha->vetor[pilha->topo]);
    }else{
        printf("Pilha está vazia! \n");
    }
}


int PCheia(Pilha *pilha){
    if(pilha->topo >=MAXTAM){
        return 1;
    }else{
        return 0;
    }
}

int PVazia(Pilha *pilha){
    if(pilha->topo == 0){
        return 1;
    }else{
        return 0;
    }
}

void ImprimirP(Pilha *pilha){
    printf("======RESULTADO DA PILHA======\n");
    int i;
    for(i=(pilha->topo);i--;i>=0){
        printf("%02d\n", pilha->vetor[i]);
    }
    printf("==============================\n");
}

int main(){
    Pilha p;
    p.topo = 0;


    empilhar(10,&p); //1
    empilhar(20,&p); //2
    empilhar(30,&p); //3
    empilhar(40,&p); //4
    empilhar(50,&p); //5

    printf("Topo da pilha: %d \n", p.topo);
    ImprimirP(&p);
    return 0;
}