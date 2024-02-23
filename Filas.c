#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {

    // exemplo de uso da fila
    Fila* fila1 = criarFila();

    enqueue(fila1, 10);
    enqueue(fila1, 20);
    enqueue(fila1, 30);


   /* if (estaVazio(fila))
    	printf("Fila vazia.\n");
    else 
    	printf("Fila não está vazia.\n");

    destruirFila(fila);

    return 0;*/
     Fila* fila2 = criarFila();

     enqueue(fila2, 01);
     enqueue(fila2, 02);
     enqueue(fila2, 03);
     enqueue(fila2, 04);

     concatenaFilas(fila1, fila2);
     imprimeFila(fila1);

     

}



// função para criar uma fila vazia
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL) {
        fprintf(stderr, "Erro na alocação de memória para a fila\n");
        exit(EXIT_FAILURE);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

// função para destruir a fila e liberar memória
void destruirFila(Fila* fila) {
    while (fila->inicio != NULL) {
        Nodo* temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp);
    }
    free(fila);
}

// função para inserir um elemento no final da fila
void enqueue(Fila* fila, int valor) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }
    novo->info = valor;
    novo->prox = NULL;
    if (fila->inicio == NULL) {  // fila vazia
        fila->inicio = novo;
    } else {  // fila não vazia
        fila->fim->prox = novo;
    }
    fila->fim = novo;
}

// função para remover e retornar o elemento da frente (início) da fila
int dequeue(Fila* fila) {
    if (fila->inicio == NULL) {
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE);
    }
    Nodo* temp = fila->inicio;
    int data = temp->info;
    fila->inicio = temp->prox;
    free(temp);
    return data;
}

// função para verificar se a fila está vazia
int estaVazio(Fila* fila) {
    return (fila->inicio == NULL);
}

void imprimeFila(Fila* fila){

    if (estaVazio(fila))
    {
        printf("Fila vazia");
    }else{
        Nodo* aux = fila->inicio;
        printf("Fila:");
        while (aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        
    }
    
}

//comparar filas
int maiorfila(Fila* f1, Fila* f2 ){
    
    Nodo* aux_f1 = f1->inicio;
    Nodo* aux_f2 = f2->inicio;

    int count_f1 = 0, count_f2 = 0;

    while (aux_f1 != NULL){
        count_f1++;
        aux_f1 = aux_f1->prox;
    }
    while (aux_f2 != NULL){
        count_f2++;
        aux_f2 = aux_f2->prox;
    }

    if (count_f1 > count_f2){
        return 1;
    }else if (count_f1 < count_f2){
        return -1;
    }else{
        return 0;
    }
    
}

//concatena as filas f1 e f2, botando o resultado em f1 e esvaziando f2
void concatenaFilas(Fila* f1, Fila* f2){

    while (!estaVazio(f2)){
        enqueue(f1, dequeue(f2));
    }
    
}
