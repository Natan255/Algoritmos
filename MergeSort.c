#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int array[], int inicio, int meio, int fim){

    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;

    int esquerda[tam1];
    int direita[tam2];

    int i, j, k;

    
    for(i = 0; i < tam1 ; i++){

        esquerda[i] = array[inicio + i];
    }

    for(j = 0; j < tam2 ; j++){

        direita[j] = array[meio + 1 + j];
    }
    i = 0;
    j = 0;
    k = inicio;
    
    while (i < tam1 && j < tam2)
    {
        if(esquerda[i] >= direita[j]){
            array[k] = direita[j];
            j++;
        }else{
            array[k] = esquerda[i];
            i++;
        }
        k++;
    }

    while (i < tam1)
    {
        array[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tam2)
    {
        array[k] = direita[j];
        j++;
        k++;
    }
    
}

void printar(int Array[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        if (i == tamanho - 1)
            printf("%d", Array[i]);
        else
            printf("%d, ", Array[i]);
    }
    printf("]\n");
}


void mergeSort(int array[], int inicio, int fim){

    if(inicio < fim){
        int meio = inicio / 2 + fim / 2; //evita overflow
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);

    }

}


int main(){
    srand(time(NULL));
    int Array[10]; 

    for(int i = 0; i < 10; i++){

        Array[i] = rand()%100;

    }
    printf("Array antes da ordenação: \n");
    printar(Array, 10);
    mergeSort(Array, 0, 9);
    printf("---------------------------------\n");
    printf("Array depois da ordenação: \n");
    printar(Array, 10);

    

}