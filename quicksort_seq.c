#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "partition.h"

#define TAMANHO_MAXIMO 100000000

// Função Quicksort paralela usando OpenMP
void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        // Particionar o array e obter o índice do pivô
        int pi = particionar(arr, baixo, alto);

        // Executar a chamada recursiva para cada metade do array em paralelo
        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}

// Função principal
int main()
{
  // Seed para a função rand
  srand(time(NULL));

  int tamanho = TAMANHO_MAXIMO; // Tamanho do vetor

  // Alocar memória dinamicamente para o vetor
  int *arr = (int *)malloc(tamanho * sizeof(int));

  // Preencher o vetor com valores aleatórios
  for (int i = 0; i < tamanho; i++)   {
    arr[i] = rand() % tamanho; // Gera valores aleatórios entre 0 e 9999
  }

  printf("Array original (%d): \n", tamanho);
  imprimir_array(arr);

  quicksort(arr, 0, tamanho - 1);

  printf("\nArray ordenado (%d): \n", tamanho);
  imprimir_array(arr);
  if(validar_array_ordenado(arr, tamanho)) {
    fprintf(stderr, "ERRO arr\n");
  }
  return 0;
}
