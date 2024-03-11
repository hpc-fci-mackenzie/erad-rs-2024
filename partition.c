#include "partition.h"
#include <stdio.h>

// Função para trocar dois elementos de um array
void trocar(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Função para dividir o array e retornar o índice do pivô
int particionar(int arr[], int baixo, int alto)
{
  int pivot = arr[alto]; // Pivot
  int i = (baixo - 1);   // Indice do menor elemento

  for (int j = baixo; j <= alto - 1; j++)
  {
    // Se o elemento atual for menor ou igual ao pivot
    if (arr[j] <= pivot)
    {
      i++;                      // Incrementar o índice do menor elemento
      trocar(&arr[i], &arr[j]); // Trocar arr[i] e arr[j]
    }
  }
  trocar(&arr[i + 1], &arr[alto]); // Colocar o pivot no lugar certo
  return (i + 1);
}

// Função para imprimir um array
void imprimir_array(int arr[])
{
  for (int i = 0; i < 20; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int validar_array_ordenado(int arr[], int n)
{
  if(!n) return -1;
  for (int i = 1; i < n; i++) {
    if(arr[i] < arr[i-1]) {
      return i;
    }
  }
  return 0;
}
